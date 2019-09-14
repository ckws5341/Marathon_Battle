// Fill out your copyright notice in the Description page of Project Settings.

#include "Greece.h"
#include "Misc/Paths.h"				
#include "EngineUtils.h"

// Sets default values
AGreece::AGreece()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGreece::BeginPlay()
{
	Super::BeginPlay();

	flag_valid_poseable_char_ = InitPoseableCharacter();

	FString T_pose_filename	        = FPaths::ProjectContentDir() + "bvh/T_pose.bvh";	// T-Pose 자세를 저장하고있는 모션 데이터 파일
	FString turn_180_1_filename     = FPaths::ProjectContentDir() + "bvh/greece_bvh/180turn_1.bvh";
	FString attack_1_filename       = FPaths::ProjectContentDir() + "bvh/greece_bvh/attack_1.bvh";
	FString attack_2_filename       = FPaths::ProjectContentDir() + "bvh/greece_bvh/attack_2.bvh";
	FString attack_3_filename       = FPaths::ProjectContentDir() + "bvh/greece_bvh/attack_3.bvh";
	FString attack_4_filename       = FPaths::ProjectContentDir() + "bvh/greece_bvh/attack_4.bvh";
	FString death_backward_filename = FPaths::ProjectContentDir() + "bvh/greece_bvh/death_backward.bvh";
	FString death_forward_filename  = FPaths::ProjectContentDir() + "bvh/greece_bvh/death_forward.bvh";
	FString backwalk_filename       = FPaths::ProjectContentDir() + "bvh/greece_bvh/backwalk.bvh";
	FString draw_1_filename         = FPaths::ProjectContentDir() + "bvh/greece_bvh/draw_1.bvh";
	FString draw_2_filename         = FPaths::ProjectContentDir() + "bvh/greece_bvh/draw_2.bvh";
	FString kick_filename           = FPaths::ProjectContentDir() + "bvh/greece_bvh/kick.bvh";
	FString running_filename        = FPaths::ProjectContentDir() + "bvh/greece_bvh/running.bvh";
	FString blocking_1_filename     = FPaths::ProjectContentDir() + "bvh/greece_bvh/blocking_1.bvh";
	FString blocking_2_filename     = FPaths::ProjectContentDir() + "bvh/greece_bvh/blocking_2.bvh";
	FString sword_slash_1_filename  = FPaths::ProjectContentDir() + "bvh/greece_bvh/sword_slash_1.bvh";
	FString sword_slash_2_filename  = FPaths::ProjectContentDir() + "bvh/greece_bvh/sword_slash_2.bvh";
	FString sword_slash_3_filename  = FPaths::ProjectContentDir() + "bvh/greece_bvh/sword_slash_3.bvh";
	FString walking_filename        = FPaths::ProjectContentDir() + "bvh/greece_bvh/walking.bvh";

	ml::Motion	turn_180_1;
	ml::Motion	attack_1;
	ml::Motion	attack_2;
	ml::Motion	attack_3;
	ml::Motion	attack_4;
	ml::Motion	death_backward;
	ml::Motion	death_forward;
	ml::Motion	backwalk;
	ml::Motion	draw_1;
	ml::Motion	draw_2;
	ml::Motion	kick;
	ml::Motion	running;
	ml::Motion	blocking_1;
	ml::Motion	blocking_2;
	ml::Motion	sword_slash_1;
	ml::Motion	sword_slash_2;
	ml::Motion	sword_slash_3;
	ml::Motion  walking;

	ml::LoadBVH_UE4(T_pose_filename, turn_180_1_filename,  turn_180_1);
	ml::LoadBVH_UE4(T_pose_filename, attack_1_filename,  attack_1);
	ml::LoadBVH_UE4(T_pose_filename, attack_2_filename,  attack_2);
	ml::LoadBVH_UE4(T_pose_filename, attack_3_filename,  attack_3);
	ml::LoadBVH_UE4(T_pose_filename, attack_4_filename,  attack_4);
	ml::LoadBVH_UE4(T_pose_filename, death_backward_filename,  death_backward);
	ml::LoadBVH_UE4(T_pose_filename, death_forward_filename,  death_forward);
	ml::LoadBVH_UE4(T_pose_filename, backwalk_filename,  backwalk);
	ml::LoadBVH_UE4(T_pose_filename, draw_1_filename,  draw_1);
	ml::LoadBVH_UE4(T_pose_filename, draw_2_filename,  draw_2);
	ml::LoadBVH_UE4(T_pose_filename, kick_filename, kick);
	ml::LoadBVH_UE4(T_pose_filename, running_filename,  running);
	ml::LoadBVH_UE4(T_pose_filename, blocking_1_filename,  blocking_1);
	ml::LoadBVH_UE4(T_pose_filename, blocking_2_filename,  blocking_2);
	ml::LoadBVH_UE4(T_pose_filename, sword_slash_1_filename,  sword_slash_1);
	ml::LoadBVH_UE4(T_pose_filename, sword_slash_2_filename,  sword_slash_2);
	ml::LoadBVH_UE4(T_pose_filename, sword_slash_3_filename,  sword_slash_3);
	ml::LoadBVH_UE4(T_pose_filename, walking_filename,  walking);

	if (CharPoseable != nullptr)
	{
		motion_ = draw_1;
		motion_.Stitch_UE4(draw_2);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(running);
	}
	if (CharPoseable1 != nullptr)
	{
		motion_ = draw_1;
		motion_.Stitch_UE4(draw_2);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(death_backward);
	}
	else if (CharPoseable2 != nullptr)
	{
		motion_ = draw_1;
		motion_.Stitch_UE4(draw_2);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(sword_slash_3);
		motion_.Stitch_UE4(blocking_1);
		motion_.Stitch_UE4(blocking_2);
		motion_.Stitch_UE4(blocking_1);
		motion_.Stitch_UE4(blocking_2);
		motion_.Stitch_UE4(death_backward);

	}
	else if (CharPoseable3 != nullptr)
	{
		motion_ = draw_1;
		motion_.Stitch_UE4(draw_2);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(blocking_1);
		motion_.Stitch_UE4(blocking_2);
		motion_.Stitch_UE4(backwalk);
		motion_.Stitch_UE4(turn_180_1);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(running);
	}
	else if (CharPoseable4 != nullptr)
	{
		motion_ = draw_1;
		motion_.Stitch_UE4(draw_2);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(blocking_1);
		motion_.Stitch_UE4(death_backward);
	}
	else if (CharPoseable5 != nullptr)
	{
		motion_ = draw_1;
		motion_.Stitch_UE4(draw_2);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(sword_slash_1);
		motion_.Stitch_UE4(blocking_1);
		motion_.Stitch_UE4(blocking_2);
		motion_.Stitch_UE4(backwalk);
		motion_.Stitch_UE4(turn_180_1);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(running);

		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(running);
	}
	else if (CharPoseable6 != nullptr)
	{
		motion_ = draw_1;
		motion_.Stitch_UE4(draw_2);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(blocking_1);
		motion_.Stitch_UE4(sword_slash_3);
		motion_.Stitch_UE4(backwalk);
		motion_.Stitch_UE4(death_forward);
	}
	else if (CharPoseable7 != nullptr)
	{
		motion_ = draw_1;
		motion_.Stitch_UE4(draw_2);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(sword_slash_3);
		motion_.Stitch_UE4(blocking_1);
		motion_.Stitch_UE4(blocking_2);
		motion_.Stitch_UE4(blocking_1);
		motion_.Stitch_UE4(blocking_2);
		motion_.Stitch_UE4(sword_slash_2);
		motion_.Stitch_UE4(turn_180_1);
		motion_.Stitch_UE4(death_forward);

	}
	else if (CharPoseable8 != nullptr)
	{
		motion_ = draw_1;
		motion_.Stitch_UE4(draw_2);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(running);
		motion_.Stitch_UE4(sword_slash_1);
		motion_.Stitch_UE4(sword_slash_1);
		motion_.Stitch_UE4(blocking_2);
		motion_.Stitch_UE4(sword_slash_3);
		motion_.Stitch_UE4(blocking_1);
		motion_.Stitch_UE4(blocking_1);
		motion_.Stitch_UE4(death_backward);
	}

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
bool AGreece::InitPoseableCharacter()
{

	TArray<UPoseableMeshComponent*> components;
	GetComponents(components);

	CharPoseable = nullptr;
	CharPoseable1 = nullptr;
	CharPoseable2 = nullptr;
	CharPoseable3 = nullptr;
	CharPoseable4 = nullptr;
	CharPoseable5 = nullptr;
	CharPoseable6 = nullptr;
	CharPoseable7 = nullptr;
	CharPoseable8 = nullptr;
	for (int i = 0; i < components.Num(); i++)
	{
		if (components[i]->GetName() == "Greece")
			CharPoseable = (UPoseableMeshComponent*)components[i];
		if (components[i]->GetName() == "Greece1")
			CharPoseable1 = (UPoseableMeshComponent*)components[i];
		if (components[i]->GetName() == "Greece2")
			CharPoseable2 = (UPoseableMeshComponent*)components[i];
		if (components[i]->GetName() == "Greece3")
			CharPoseable3 = (UPoseableMeshComponent*)components[i];
		if (components[i]->GetName() == "Greece4")
			CharPoseable4 = (UPoseableMeshComponent*)components[i];
		if (components[i]->GetName() == "Greece5")
			CharPoseable5 = (UPoseableMeshComponent*)components[i];
		if (components[i]->GetName() == "Greece6")
			CharPoseable6 = (UPoseableMeshComponent*)components[i];
		if (components[i]->GetName() == "Greece7")
			CharPoseable7 = (UPoseableMeshComponent*)components[i];
		if (components[i]->GetName() == "Greece8")
			CharPoseable8 = (UPoseableMeshComponent*)components[i];
	}
	if (CharPoseable == nullptr &&
		CharPoseable1 == nullptr && CharPoseable2 == nullptr &&
		CharPoseable3 == nullptr && CharPoseable4 == nullptr &&
		CharPoseable5 == nullptr && CharPoseable6 == nullptr &&
		CharPoseable7 == nullptr && CharPoseable8 == nullptr) return false;

	if (CharPoseable != nullptr) {
		if (CharPoseable->SkeletalMesh == nullptr)
			return false;
		ml_u_poser_.SetUPoseableMeshComponent(CharPoseable);
	}

	if (CharPoseable1 != nullptr) {
		if (CharPoseable1->SkeletalMesh == nullptr)
			return false;
		ml_u_poser_.SetUPoseableMeshComponent(CharPoseable1);
	}
	if (CharPoseable2 != nullptr) {
		if (CharPoseable2->SkeletalMesh == nullptr)
			return false;
		ml_u_poser_.SetUPoseableMeshComponent(CharPoseable2);
	}
	if (CharPoseable3 != nullptr) {
		if (CharPoseable3->SkeletalMesh == nullptr)
			return false;
		ml_u_poser_.SetUPoseableMeshComponent(CharPoseable3);
	}
	if (CharPoseable4 != nullptr) {
		if (CharPoseable4->SkeletalMesh == nullptr)
			return false;
		ml_u_poser_.SetUPoseableMeshComponent(CharPoseable4);
	}
	if (CharPoseable5 != nullptr) {
		if (CharPoseable5->SkeletalMesh == nullptr)
			return false;
		ml_u_poser_.SetUPoseableMeshComponent(CharPoseable5);
	}
	if (CharPoseable6 != nullptr) {
		if (CharPoseable6->SkeletalMesh == nullptr)
			return false;
		ml_u_poser_.SetUPoseableMeshComponent(CharPoseable6);
	}
	if (CharPoseable7 != nullptr) {
		if (CharPoseable7->SkeletalMesh == nullptr)
			return false;
		ml_u_poser_.SetUPoseableMeshComponent(CharPoseable7);
	}
	if (CharPoseable8 != nullptr) {
		if (CharPoseable8->SkeletalMesh == nullptr)
			return false;
		ml_u_poser_.SetUPoseableMeshComponent(CharPoseable8);
	}

	//// 2.2 캐릭터 모델 인체 부위 이름 지정
	// 각각의 캐릭터 모델의 신체 부위 이름은 제작자가 임의로 부여하기 때문에 서로 다를 것이다.
	// ML library를 사용하기 위해서는 각 인체 부위에 사전에 약속된 이름(JointTag)을 부여하여야 한다.
	// SetJointTag("캐릭터 모델 상의 신체 이름", "ML library에 정의 된 이름").

	ml_u_poser_.SetJointTag("Hips", ml::PELVIS);
	ml_u_poser_.SetJointTag("Spine", ml::SPINE);
	ml_u_poser_.SetJointTag("Spine1", ml::SPINE1);
	ml_u_poser_.SetJointTag("Spine2", ml::CHEST);
	ml_u_poser_.SetJointTag("Neck", ml::NECK);
	ml_u_poser_.SetJointTag("Head", ml::HEAD);

	ml_u_poser_.SetJointTag("RightUpLeg", ml::R_HIP);
	ml_u_poser_.SetJointTag("RightLeg", ml::R_KNEE);
	ml_u_poser_.SetJointTag("RightFoot", ml::R_ANKLE);
	ml_u_poser_.SetJointTag("RightToeBase", ml::R_FOOT);

	ml_u_poser_.SetJointTag("LeftUpLeg", ml::L_HIP);
	ml_u_poser_.SetJointTag("LeftLeg", ml::L_KNEE);
	ml_u_poser_.SetJointTag("LeftFoot", ml::L_ANKLE);
	ml_u_poser_.SetJointTag("LeftToeBase", ml::L_FOOT);


	ml_u_poser_.SetJointTag("RightShoulder", ml::R_CLAVICLE);
	ml_u_poser_.SetJointTag("RightArm", ml::R_SHOULDER);
	ml_u_poser_.SetJointTag("RightForeArm", ml::R_ELBOW);
	ml_u_poser_.SetJointTag("RightHand", ml::R_WRIST);

	ml_u_poser_.SetJointTag("LeftShoulder", ml::L_CLAVICLE);
	ml_u_poser_.SetJointTag("LeftArm", ml::L_SHOULDER);
	ml_u_poser_.SetJointTag("LeftForeArm", ml::L_ELBOW);
	ml_u_poser_.SetJointTag("LeftHand", ml::L_WRIST);


	//// 2.3 위에 설정된 내용을 바탕으로 'ml_u_poser' 내부 데이터를 업데이트한다.
	// 'BuildSkeleton()' 함수는 반드시 2.1과 2.2의 설정이 끝난후 실행되어야한다.
	ml_u_poser_.BuildSkeleton();

	return true;

}
// Called every frame
void AGreece::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CharPoseable == nullptr &&
		CharPoseable1 == nullptr && CharPoseable2 == nullptr &&
		CharPoseable3 == nullptr && CharPoseable4 == nullptr &&
		CharPoseable5 == nullptr && CharPoseable6 == nullptr &&
		CharPoseable7 == nullptr && CharPoseable8 == nullptr) return;

	if (flag_valid_poseable_char_ == false) return;

	if (motion_.size() == 0) return;

	float t = GetGameTimeSinceCreation();


	if (CharPoseable != nullptr)
	{
		ml::Posture pose = motion_.GetPostureAtTime_ms(t);
		ml_u_poser_.Retarget(pose);
	}
	if (t > 5.f)
	{
		ml::Posture pose = motion_.GetPostureAtTime_ms(t - 4.f);
		ml_u_poser_.Retarget(pose);
	}
}

