// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor() : TotalDamage(200), DamageTimeInSeconds(1.0f)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PostInitProperties();
//	TotalDamage = 200;
//	DamageTimeInSeconds = 1.0f;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActor::PostInitProperties()
{
	Super::PostInitProperties();
	//DamagePerSecond = TotalDamage / DamageTimeInSeconds;
	CalcuateValues();
}

void AMyActor::CalcuateValues()
{
	DamagePerSecond = TotalDamage / DamageTimeInSeconds;
}

#if WITH_EDITOR
void AMyActor::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	CalcuateValues();

	Super::PostEditChangeProperty(PropertyChangedEvent);
}
#endif

//void AMyActor::CalledFromCpp()
//{
//
//}
//
//void AMyActor::CalledFromCpp_Implementation()
//{
//	// how to job
//}