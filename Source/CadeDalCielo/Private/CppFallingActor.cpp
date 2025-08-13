// Fill out your copyright notice in the Description page of Project Settings.


#include "CppFallingActor.h"

// Sets default values
ACppFallingActor::ACppFallingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(RootComponent);
	MeshComponent->SetSimulatePhysics(true);
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::Type::QueryAndPhysics);
	MeshComponent->SetCollisionObjectType(ECC_WorldDynamic);
	MeshComponent->OnComponentBeginOverlap.AddDynamic(this, &ACppFallingActor::OnComponentBeginOverlap);
	MeshComponent->SetRelativeScale3D(FVector(0.6f));
}

// Called when the game starts or when spawned
void ACppFallingActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACppFallingActor::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	OnObjectCollected.Broadcast();
	
	MeshComponent->SetSimulatePhysics(false);
	Destroy();
}

// Called every frame
void ACppFallingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

