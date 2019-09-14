// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/PoseableMeshComponent.h"
#include "Motion/ml.h"
#include "Dispatch_Rider.generated.h"

UCLASS()
class FINAL_PROJECT_API ADispatch_Rider : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADispatch_Rider();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	bool InitPoseableCharacter();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPoseableMeshComponent * CharPoseable;
	bool flag_valid_poseable_char_;

	ml::Motion motion_;
	ml::UE4Poser ml_u_poser_;

};
