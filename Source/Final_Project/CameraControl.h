// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CameraControl.generated.h"

UCLASS()
class FINAL_PROJECT_API ACameraControl : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACameraControl();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere) AActor* CameraOne;
	UPROPERTY(EditAnywhere) AActor* CameraTwo;
	UPROPERTY(EditAnywhere) AActor* CameraThree;
	UPROPERTY(EditAnywhere) AActor* CameraFour;
	UPROPERTY(EditAnywhere) AActor* CameraFive;
	UPROPERTY(EditAnywhere) AActor* CameraSix;
	UPROPERTY(EditAnywhere) AActor* CameraSeven;
	UPROPERTY(EditAnywhere) AActor* CameraEight;
	UPROPERTY(EditAnywhere) AActor* CameraNine;
	UPROPERTY(EditAnywhere) AActor* CameraTen;
	UPROPERTY(EditAnywhere) AActor* CameraEleven;
	UPROPERTY(EditAnywhere) AActor* CameraTwelve;
	UPROPERTY(EditAnywhere) AActor* CameraThirteen;
	UPROPERTY(EditAnywhere) AActor* CameraFourteen;
	float TimeToNextCameraChange = 0.f;

};
