// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GMode.generated.h"

class UScoreHUD;
/**
 * 
 */
UCLASS()
class CADEDALCIELO_API AGMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	UScoreHUD* GetScoreHud() const {return ScoreHUDRef;}

	int32 CalculateScore();
	
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UScoreHUD> ScoreHUDClass;
	
	UScoreHUD* ScoreHUDRef;

private:
	int32 m_Score;
};
