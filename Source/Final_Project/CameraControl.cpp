// Fill out your copyright notice in the Description page of Project Settings.

#include "CameraControl.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACameraControl::ACameraControl()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACameraControl::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACameraControl::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const float SmoothBlendTime = 2.f;
	const float MarathonBlendTime = 21.f;
	TimeToNextCameraChange += DeltaTime;
	if (TimeToNextCameraChange < 1.0f)
	{
		APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
		if (OurPlayerController)
		{
			if (CameraOne != nullptr)
				OurPlayerController->SetViewTarget(CameraOne);
		}
	}
	if (TimeToNextCameraChange >= 1.0f && TimeToNextCameraChange < 5.0f)
	{
		APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
		if (OurPlayerController)
		{
			if (CameraTwo != nullptr)
				OurPlayerController->SetViewTargetWithBlend(CameraTwo, SmoothBlendTime);
		}
	}
	if (TimeToNextCameraChange >= 5.0f && TimeToNextCameraChange < 11.0f)
	{
		APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
		if (OurPlayerController)
		{
			if(CameraThree != nullptr)
				OurPlayerController->SetViewTarget(CameraThree);
		}
	}
	else if (TimeToNextCameraChange >= 11.0f && TimeToNextCameraChange < 23.0f)
	{
		APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
		if (OurPlayerController)
		{
			if (CameraFour != nullptr)
				OurPlayerController->SetViewTargetWithBlend(CameraFour, SmoothBlendTime);
		}
	}
	if (TimeToNextCameraChange >= 23.0f && TimeToNextCameraChange < 24.5f)
	{
		APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
		if (OurPlayerController)
		{
			if (CameraFive != nullptr)
				OurPlayerController->SetViewTarget(CameraFive);
		}
	}
	if (TimeToNextCameraChange >= 24.5f && TimeToNextCameraChange < 27.f)
	{
		APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
		if (OurPlayerController)
		{
			if (CameraSix != nullptr)
				OurPlayerController->SetViewTargetWithBlend(CameraSix, SmoothBlendTime);
		}
	}
	if (TimeToNextCameraChange >= 27.f && TimeToNextCameraChange < 50.f)
	{
		APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
		if (OurPlayerController)
		{
			if (CameraSeven != nullptr)
				OurPlayerController->SetViewTarget(CameraSeven);
		}
	}
	if (TimeToNextCameraChange >= 50.f && TimeToNextCameraChange < 58.f)
	{
		APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
		if (OurPlayerController)
		{
			if (CameraEight != nullptr)
				OurPlayerController->SetViewTarget(CameraEight);
		}
	}
	if (TimeToNextCameraChange >= 58.f && TimeToNextCameraChange < 62.f)
	{
		APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
		if (OurPlayerController)
		{
			if (CameraNine != nullptr)
				OurPlayerController->SetViewTarget(CameraNine);
		}
	}
	if (TimeToNextCameraChange >= 62.f && TimeToNextCameraChange < 83.f)
	{
		APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
		if (OurPlayerController)
		{
			if (CameraTen != nullptr)
				OurPlayerController->SetViewTargetWithBlend(CameraTen, MarathonBlendTime);
		}
	}
	if (TimeToNextCameraChange >= 83.f && TimeToNextCameraChange < 90)
	{
		APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
		if (OurPlayerController)
		{
			if (CameraEleven != nullptr)
				OurPlayerController->SetViewTarget(CameraEleven);
		}
	}
	if (TimeToNextCameraChange >= 90.f && TimeToNextCameraChange < 97.f)
	{
		APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
		if (OurPlayerController)
		{
			if (CameraTwelve != nullptr)
				OurPlayerController->SetViewTarget(CameraTwelve);
		}
	}
	if (TimeToNextCameraChange >= 97.f && TimeToNextCameraChange < 107.f)
	{
		APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
		if (OurPlayerController)
		{
			if (CameraThirteen != nullptr)
				OurPlayerController->SetViewTarget(CameraThirteen);
		}
	}
	if (TimeToNextCameraChange >= 107.f)
	{
		APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
		if (OurPlayerController)
		{
			if (CameraFourteen != nullptr)
				OurPlayerController->SetViewTargetWithBlend(CameraFourteen, SmoothBlendTime);
		}
	}
}

