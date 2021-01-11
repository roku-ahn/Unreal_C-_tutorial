// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
//class UNREALTEST1_API AMyActor : public AActor
class AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage") //블루프린트와 에디터에 보여줌
	int32 TotalDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
		float DamageTimeInSeconds;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Transient, Category = "Damage")
		float DamagePerSecond;

	virtual void PostInitProperties() override;
#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

	UFUNCTION(BlueprintCallable,Category="Damage")
	void CalcuateValues();
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Damage")
	void CalledFromCppNotWriteCpp();

	//UFUNCTION(BlueprintNativeEvent, Category = "Damage")  //블루프린트 가상 머신 호출 썽크 매서드
	//void CalledFromCpp();
	//virtual void CalledFromCpp_Implementation();
};
