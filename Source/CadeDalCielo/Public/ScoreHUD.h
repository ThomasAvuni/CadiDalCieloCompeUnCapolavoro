// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ScoreHUD.generated.h"

/**
 * 
 */
UCLASS()
class CADEDALCIELO_API UScoreHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void UpdateScoreUI(int32 NewScore);
	
};
