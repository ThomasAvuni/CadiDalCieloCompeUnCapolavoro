// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObjectSpawner.generated.h"

class ACppFallingActor;
class UBoxComponent;

UCLASS()
class CADEDALCIELO_API AObjectSpawner : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AObjectSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UBoxComponent* BoxComp;

	UPROPERTY(EditAnywhere)
	TSubclassOf<ACppFallingActor> FallingActorClassRef;
	
	FTimerHandle m_SpawnTimer;

	UFUNCTION()
	void OnObjectCollected();
	
private:
	void SpawnItem();
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
