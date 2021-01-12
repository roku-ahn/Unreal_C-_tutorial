// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CameraDirector.generated.h"


UCLASS()
class UNREALTEST1_API ACameraDirector : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACameraDirector();

	UPROPERTY(EditAnywhere)
		AActor* CameraOne;

	UPROPERTY(EditAnywhere)
		AActor* CameraTwo;

	UPROPERTY(EditAnywhere)
		AActor* CameraMove;

	float TimeToNextCameraChange;
	void Move_XY(float AxisXValue,float AxisYValue);
	FVector CurrentVelocity;
	float startx;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
