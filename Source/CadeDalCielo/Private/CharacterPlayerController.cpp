// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterPlayerController.h"

#include "EnhancedInputSubsystemInterface.h"
#include "EnhancedInputSubsystems.h"

void ACharacterPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputLocalPlayerSubsystem *Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		if (MappingContext)
		{
			Subsystem->AddMappingContext(MappingContext, 0);
		}
	}
}
