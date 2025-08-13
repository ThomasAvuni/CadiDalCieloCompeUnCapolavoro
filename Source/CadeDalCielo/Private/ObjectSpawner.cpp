// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectSpawner.h"

#include "GMode.h"
#include "ScoreHUD.h"
#include "Components/BoxComponent.h"
#include "CadeDalCielo/Public/CppFallingActor.h"
#include "GameFramework/GameModeBase.h"

// Sets default values
AObjectSpawner::AObjectSpawner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComp = CreateDefaultSubobject<UBoxComponent>("Box");
	BoxComp->SetBoxExtent({400, 400, 40});
}

// Called when the game starts or when spawned
void AObjectSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorldTimerManager().SetTimer(m_SpawnTimer, this, &AObjectSpawner::SpawnItem, 0.5f, true);
}

void AObjectSpawner::SpawnItem()
{
	if (FallingActorClassRef)
	{
		FVector Location = GetActorLocation();
		FRotator Rotation = FRotator::ZeroRotator;
		ACppFallingActor* Spawned = GetWorld()->SpawnActor<ACppFallingActor>(FallingActorClassRef, Location, Rotation);
		Spawned->OnObjectCollected.AddDynamic(this, &AObjectSpawner::OnObjectCollected);
	}
}

void AObjectSpawner::OnObjectCollected()
{
	if (AGMode* GM = Cast<AGMode>(GetWorld()->GetAuthGameMode()))
	{
		GM->GetScoreHud()->UpdateScoreUI(GM->CalculateScore());
	}
}

// Called every frame
void AObjectSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

