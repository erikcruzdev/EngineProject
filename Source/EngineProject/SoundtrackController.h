// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SoundtrackController.generated.h"

UCLASS(Blueprintable)
class ENGINEPROJECT_API ASoundtrackController : public AActor
{
	GENERATED_BODY()
	
public:	

	UFUNCTION(BlueprintPure)
	static ASoundtrackController* GetSoundtrackController() { return _instance; }

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void PlaySoundtrack(USoundBase* sound);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	static ASoundtrackController* _instance;
};
