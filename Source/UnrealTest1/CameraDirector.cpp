// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraDirector.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/StaticMeshActor.h"

// Sets default values
ACameraDirector::ACameraDirector()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    TimeToNextCameraChange = 0;
    
    
}

// Called when the game starts or when spawned
void ACameraDirector::BeginPlay()
{
	Super::BeginPlay();


    TSubclassOf<class AStaticMeshActor> findactor = AStaticMeshActor::StaticClass();

    TArray<AActor*>actors;

    UGameplayStatics::GetAllActorsOfClass(GetWorld(), findactor, actors);
    for (AActor* actor : actors)
    {
        if (actor->GetName() == "moveCube")
        {
            CameraMove = actor;
            CurrentVelocity = CameraMove->GetActorLocation();
            startx = CurrentVelocity.X;
            APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
            OurPlayerController->SetViewTarget(CameraMove);
            //moveCubu�� �����Ƽ�� ������ �̿��� �Ѵ�.
        }
    }
	
}
void ACameraDirector::Move_XY(float AxisXValue, float AxisYValue)
{
    CurrentVelocity.X = FMath::Clamp(AxisXValue, -1.0f, 1.0f) * 100.0f;
    CurrentVelocity.Y = FMath::Clamp(AxisYValue, -1.0f, 1.0f) * 100.0f;
}
// Called every frame
void ACameraDirector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//const float TimeBetweenCameraChanges = 2.0f;
    const float TimeBetweenCameraChanges = 1.0f;
	const float SmoothBlendTime = 0.75f;
	TimeToNextCameraChange -= DeltaTime;

    if(TimeToNextCameraChange <= 0.0f)
    {
        TimeToNextCameraChange += TimeBetweenCameraChanges;

        //// ���� �÷��̾��� ��Ʈ���� ó���ϴ� ���͸� ã���ϴ�.
        //APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
        //if (OurPlayerController)
        //{
        //    if ((OurPlayerController->GetViewTarget() != CameraOne) && (CameraOne != nullptr))
        //    {
        //        // 1 �� ī�޶�� ��� ���� ���ϴ�.
        //        OurPlayerController->SetViewTargetWithBlend(CameraOne, SmoothBlendTime);
        //    }
        //    else if ((OurPlayerController->GetViewTarget() != CameraTwo) && (CameraTwo != nullptr))
        //    {
        //        // 2 �� ī�޶�� �ε巴�� ��ȯ�մϴ�.
        //        OurPlayerController->SetViewTarget(CameraTwo);
        //    }
        //}
        if (CameraMove != NULL)
        {
            FVector cur = CameraMove->GetActorLocation();
            FVector move = cur + FVector(-10.0f, 0.0f, 0.0f);
            CameraMove->SetActorLocation(move);
            SetActorLocation(move);
            if (CameraMove->GetActorLocation().X <= 0)
                CameraMove->SetActorLocation(FVector(startx, 0.0f, 0.0f));

        }
    }

}

