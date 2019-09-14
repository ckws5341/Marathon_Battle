// Fill out your copyright notice in the Description page of Project Settings.

#include "Athen_General.h"
#include "Misc/Paths.h"				
#include "EngineUtils.h"

// Sets default values
AAthen_General::AAthen_General()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAthen_General::BeginPlay()
{
	Super::BeginPlay();

	flag_valid_poseable_char_ = InitPoseableCharacter();

	FString T_pose_filename			  = FPaths::ProjectContentDir() + "bvh/general_bvh/T_pose.bvh";	// T-Pose 자세를 저장하고있는 모션 데이터 파일
	FString pass_letter_filename	  = FPaths::ProjectContentDir() + "bvh/general_bvh/pass_letter.bvh";
	FString salute_filename		      = FPaths::ProjectContentDir() + "bvh/general_bvh/salute.bvh";
	FString standing_filename		  = FPaths::ProjectContentDir() + "bvh/general_bvh/standing.bvh";
	

	ml::Motion gesture;
	ml::Motion pass_letter;
	ml::Motion salute;
	ml::Motion standing;


	ml::LoadBVH_UE4(T_pose_filename, pass_letter_filename, pass_letter);
	ml::LoadBVH_UE4(T_pose_filename, salute_filename, salute);
	ml::LoadBVH_UE4(T_pose_filename, standing_filename, standing);
	
	motion_ = standing;
	motion_.Stitch_UE4(salute);
	motion_.Stitch_UE4(pass_letter);

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
bool AAthen_General::InitPoseableCharacter()
{
	TArray<UPoseableMeshComponent*> components;
	GetComponents(components);

	CharPoseable = nullptr;
	for (int i = 0; i < components.Num(); i++)
	{
		if (components[i]->GetName() == "General")
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
void AAthen_General::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CharPoseable == nullptr) return;
	if (flag_valid_poseable_char_ == false) return;
	if (motion_.size() == 0) return;

	float t = GetGameTimeSinceCreation();

	if (t > 23.f)
	{
		ml::Posture pose = motion_.GetPostureAtTime_ms(t - 22.f);
		ml_u_poser_.Retarget(pose);
	}

	/*
	TArray<UMeshComponent*> components;
	GetComponents(components);
	for (int i = 0; i < components.Num(); i++)
	{
		if (components[i]->GetName() == "letter")
		{
			FVector p;
			cml::vector3 pp = pose.GetGlobalTranslation(ml::L_PALM);
			p.X = pp[0];
			p.Y = pp[1];
			p.Z = pp[2];
			components[i]->SetRelativeLocation(p);
			break;
		}
	}*/

	
}

