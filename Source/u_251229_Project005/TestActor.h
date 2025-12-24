// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestActor.generated.h"

UCLASS()
class U_251229_PROJECT005_API ATestActor : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MoveData")
	FVector startPosition;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MoveData")
	FVector minMove;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MoveData")
	FVector maxMove;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MoveData")
	float rotSpeed;

public:	
	// Sets default values for this actor's properties
	ATestActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Turn();
	void Move();
	void RandomEvent();
};
