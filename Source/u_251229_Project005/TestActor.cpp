// Fill out your copyright notice in the Description page of Project Settings.


#include "TestActor.h"
#include "Engine/Engine.h"

// Sets default values
ATestActor::ATestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	startPosition = FVector(0.f, 50.f, 0.f);
	minMove = FVector(-1000.f, -1000.f, 0.f);
	maxMove = FVector(1000.f, 1000.f, 100.f);
	rotSpeed = 360.f;
}

// Called when the game starts or when spawned
void ATestActor::BeginPlay()
{
	Super::BeginPlay();
  SetActorLocation(startPosition);

	if (!GEngine) return;

	FTransform ActorTransform = GetActorTransform();

	float DistCalculate = 0;
	int EventCalculate = 0;

	for (int i = 0; i < 10; i++) {
		FVector Location = ActorTransform.GetLocation();
		Turn();
    Move();
		FVector NewLocation = GetActorTransform().GetLocation();

		float DistToAdd = FVector::Dist(Location, NewLocation);
    DistCalculate += DistToAdd;

		FString LocationString = FString::Printf(TEXT("Moved location: X=%f, Y=%f, Z=%f"), NewLocation.X, NewLocation.Y, NewLocation.Z);
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, LocationString);

		int RandChance = FMath::RandRange(1, 100);
		if (RandChance > 50) {
			RandomEvent();
			EventCalculate += 1;
		}
  }

	FString DistString = FString::Printf(TEXT("Total Distance Moved: %f"), DistCalculate);
  FString EventString = FString::Printf(TEXT("Total Events Triggered: %d"), EventCalculate);
  GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Blue, DistString);
  GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Blue, EventString);
}

// Called every frame
void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
  float zRot = rotSpeed * DeltaTime;
	FRotator NewRotation = GetActorRotation();
  NewRotation.Yaw += zRot;
	SetActorRotation(NewRotation);
}

void ATestActor::Turn()
{
	float randX = FMath::FRandRange(-180.f, 180.f);
  float randY = FMath::FRandRange(-180.f, 180.f);
  float randZ = FMath::FRandRange(-180.f, 180.f);
  SetActorRotation(FRotator(randX, randY, randZ));
}
void ATestActor::Move()
{
	float randX = FMath::FRandRange(minMove.X, maxMove.X);
	float randY = FMath::FRandRange(minMove.Y, maxMove.Y);
	float randZ = FMath::FRandRange(minMove.Z, maxMove.Z);
  SetActorLocation(FVector(randX, randY, randZ));
}
void ATestActor::RandomEvent()
{
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Orange, TEXT("Event excuted!"));
	}
}