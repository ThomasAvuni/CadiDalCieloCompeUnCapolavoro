// Fill out your copyright notice in the Description page of Project Settings.


#include "GMode.h"

#include "Blueprint/UserWidget.h"
#include "ScoreHUD.h"

void AGMode::BeginPlay()
{
	Super::BeginPlay();

	m_Score = 0;

	if (!ScoreHUDClass)
		return;
	
	ScoreHUDRef = CreateWidget<UScoreHUD>(GetWorld(), ScoreHUDClass);
	if (ScoreHUDRef)
	{
		ScoreHUDRef->AddToViewport();
	}
	
}

int32 AGMode::CalculateScore()
{
	return m_Score++;
}
