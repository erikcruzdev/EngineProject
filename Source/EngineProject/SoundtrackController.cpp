// Fill out your copyright notice in the Description page of Project Settings.

#include "SoundtrackController.h"

ASoundtrackController* ASoundtrackController::_instance;

// Called when the game starts or when spawned
void ASoundtrackController::BeginPlay()
{
	Super::BeginPlay();
	
	_instance = this;
}
