// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyAIController.h"

#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "Engine.h"

#include "EnemyCharacterInterface.h"

void AEnemyAIController::BeginPlay()
{
	Super::BeginPlay();

	//*((int*)0x12345678) = 5;

	UE_LOG(LogTemp, Warning, TEXT("MEU PAU NO TEU CU"));

	PrimaryActorTick.bCanEverTick = true;
}

void AEnemyAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	//UAIBlueprintHelperLibrary::SimpleMoveToActor(this, playerActor);

	if (GetPawn()->Implements<UEnemyCharacterInterface>())
	{
		TArray<AActor*> points;
		IEnemyCharacterInterface::Execute_GetPatrolPoints(GetPawn(), points);

		if (points.Num() > 0)
		{
			FVector targetPosition = points[_currentPointIndex]->GetActorLocation();
			FVector pawnPosition = GetPawn()->GetActorLocation();
			if (FVector::DistXY(targetPosition, pawnPosition) < 50.f)
			{
				_currentPointIndex = (_currentPointIndex + 1) % points.Num();
			}

			//UAIBlueprintHelperLibrary::SimpleMoveToActor(this, points[_currentPointIndex]);
		}

		//TraceCheck();
	}
}

/*
void AEnemyAIController::TraceCheck()
{
	auto* playerActor = UGameplayStatics::GetPlayerCharacter(this, 0);

	FCollisionQueryParams RV_TraceParams = FCollisionQueryParams(FName(TEXT("RV_Trace")), true, this);
	RV_TraceParams.bTraceComplex = true;
	RV_TraceParams.bTraceAsyncScene = true;
	RV_TraceParams.bReturnPhysicalMaterial = false;

	FVector Start = GetPawn()->GetActorLocation();
	FVector End = Start + (GetPawn()->GetActorForwardVector()* 700.f);

	//Re-initialize hit info
	FHitResult RV_Hit(ForceInit);

	//call GetWorld() from within an actor extending class
	GetWorld()->LineTraceSingleByChannel(
		RV_Hit,        //result
		Start,    //start
		End, //end
		ECC_Pawn, //collision channel
		RV_TraceParams
	);
	UE_LOG(LogTemp, Warning, TEXT("hit actor: %s"), *RV_Hit.GetActor()->GetName());


}*/


