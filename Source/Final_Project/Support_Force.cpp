// Fill out your copyright notice in the Description page of Project Settings.

#include "Support_Force.h"
#include "Misc/Paths.h"				
#include "EngineUtils.h"

// Sets default values
ASupport_Force::ASupport_Force()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASupport_Force::BeginPlay()
{
	Super::BeginPlay();
	
	flag_valid_poseable_char_ = InitPoseableCharacter();

	FString T_pose_filename  = FPaths::ProjectContentDir() + "bvh/support_force_bvh/T_pose.bvh";	// T-Pose 자세를 저장하고있는 모션 데이터 파일
	FString walking_filename = FPaths::ProjectContentDir() + "bvh/support_force_bvh/walking.bvh";
	FString victory_filename = FPaths::ProjectContentDir() + "bvh/support_force_bvh/victory.bvh";
	FString waiting_filename = FPaths::ProjectContentDir() + "bvh/support_force_bvh/waiting.bvh";

	ml::Motion	waiting;
	ml::Motion	walking;
	ml::Motion	victory;

	ml::LoadBVH_UE4(T_pose_filename, waiting_filename, waiting);
	ml::LoadBVH_UE4(T_pose_filename, walking_filename, walking);
	ml::LoadBVH_UE4(T_pose_filename, victory_filename, victory);
	
	motion_ = walking;
	motion_.Stitch_UE4(walking);
	motion_.Stitch_UE4(walking);
	motion_.Stitch_UE4(walking);
	motion_.Stitch_UE4(waiting);
	motion_.Stitch_UE4(waiting);
	motion_.Stitch_UE4(waiting);
	motion_.Stitch_UE4(waiting);
	motion_.Stitch_UE4(waiting);
	motion_.Stitch_UE4(waiting);
	motion_.Stitch_UE4(waiting);
	motion_.Stitch_UE4(victory);
	motion_.Stitch_UE4(victory);
	motion_.Stitch_UE4(victory);
	motion_.Stitch_UE4(victory);
	motion_.Stitch_UE4(waiting);
	motion_.Stitch_UE4(waiting);
	motion_.Stitch_UE4(waiting);

	motion_.editable_body()->SetJointTag("Hips", ml::PELVIS);
	motion_.editable_body()->SetJointTag("Spine", ml::SPINE);
	motion_.editable_body()->SetJointTag("Spine1", ml::SPINE1);
	motion_.editable_body()->SetJointTag("Spine2", ml::CHEST);
	motion_.editable_body()->SetJointTag("Neck", ml::NECK);
	motion_.editable_body()->SetJointTag("Head", ml::HEAD);

	motion_.editable_body()->SetJointTag("RightUpLeg", ml::R_HIP);
	motion_.editable_body()->SetJointTag("RightLeg", ml::R_KNEE);
	motion_.editable_body()->SetJointTag("RightFoot", ml::R_ANKLE);
	motion_.editable_body()->SetJointTag("RightToeBase", ml::R_FOOT);

	motion_.editable_body()->SetJointTag("LeftUpLeg", ml::L_HIP);
	motion_.editable_body()->SetJointTag("LeftLeg", ml::L_KNEE);
	motion_.editable_body()->SetJointTag("LeftFoot", ml::L_ANKLE);
	motion_.editable_body()->SetJointTag("LeftToeBase", ml::L_FOOT);

	//motion_.editable_body()->SetJointTag("RightShoulder", ml::R_CLAVICLE);
	motion_.editable_body()->SetJointTag("RightArm", ml::R_SHOULDER);
	motion_.editable_body()->SetJointTag("RightForeArm", ml::R_ELBOW);
	motion_.editable_body()->SetJointTag("RightHand", ml::R_WRIST);

	//motion_.editable_body()->SetJointTag("LeftShoulder", ml::L_CLAVICLE);
	motion_.editable_body()->SetJointTag("LeftArm", ml::L_SHOULDER);
	motion_.editable_body()->SetJointTag("LeftForeArm", ml::L_ELBOW);
	motion_.editable_body()->SetJointTag("LeftHand", ml::L_WRIST);
}
bool ASupport_Force::InitPoseableCharacter()
{
	TArray<UPoseableMeshComponent*> components;
	GetComponents(components);

	CharPoseable = nullptr;
	for (int i = 0; i < components.Num(); i++)
	{
		if (components[i]->GetName() == "support")
			CharPoseable = (UPoseableMeshComponent*)components[i];
	}
	if (CharPoseable == nullptr) return false;

	if (CharPoseable->SkeletalMesh == nullptr) return false;

	ml_u_poser_.SetUPoseableMeshComponent(CharPoseable);

	ml_u_poser_.SetJointTag("Hips", ml::PELVIS);
	ml_u_poser_.SetJointTag("Spine", ml::SPINE);
	ml_u_poser_.SetJointTag("Spine1", ml::SPINE1);
	ml_u_poser_.SetJointTag("Spine2", ml::CHEST);
	ml_u_poser_.SetJointTag("Neck", ml::NECK);
	ml_u_poser_.SetJointTag("Head", ml::HEAD);

	ml_u_poser_.SetJointTag("LeftUpLeg", ml::L_HIP);
	ml_u_poser_.SetJointTag("LeftLeg", ml::L_KNEE);
	ml_u_poser_.SetJointTag("LeftFoot", ml::L_ANKLE);
	ml_u_poser_.SetJointTag("LeftToeBase", ml::L_FOOT);

	ml_u_poser_.SetJointTag("RightUpLeg", ml::R_HIP);
	ml_u_poser_.SetJointTag("RightLeg", ml::R_KNEE);
	ml_u_poser_.SetJointTag("RightFoot", ml::R_ANKLE);
	ml_u_poser_.SetJointTag("RightToeBase", ml::R_FOOT);

	ml_u_poser_.SetJointTag("RightShoulder", ml::R_CLAVICLE);
	ml_u_poser_.SetJointTag("RightArm", ml::R_SHOULDER);
	ml_u_poser_.SetJointTag("RightForeArm", ml::R_ELBOW);
	ml_u_poser_.SetJointTag("RightHand", ml::R_WRIST);

	ml_u_poser_.SetJointTag("LeftShoulder", ml::L_CLAVICLE);
	ml_u_poser_.SetJointTag("LeftArm", ml::L_SHOULDER);
	ml_u_poser_.SetJointTag("LeftForeArm", ml::L_ELBOW);
	ml_u_poser_.SetJointTag("LeftHand", ml::L_WRIST);

	ml_u_poser_.BuildSkeleton();

	return true;
}
// Called every frame
void ASupport_Force::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (CharPoseable == nullptr) return;
	if (flag_valid_poseable_char_ == false) return;
	if (motion_.size() == 0) return;

	float t = GetGameTimeSinceCreation();

	if (t > 83.f)
	{

		ml::Posture pose = motion_.GetPostureAtTime_ms(t - 82.f);
		ml_u_poser_.Retarget(pose);
	}
}

