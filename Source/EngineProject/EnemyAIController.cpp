// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyAIController.h"

#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"

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

	//auto* playerActor = UGameplayStatics::GetPlayerCharacter(this, 0);
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

			UAIBlueprintHelperLibrary::SimpleMoveToActor(this, points[_currentPointIndex]);
		}
	}
}