// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimerActor.generated.h"

class UWorld; // Module: Engine, #include "Engine/World.h"
class FTimerManager; // Module: Engine, #include "TimerManager.h"
// struct FTimerHandle // EngineTypes.h

/**
 * See FTimerManager::Tick
 */
UCLASS()
class LEARNINGUE4_API ATimerActor : public AActor
{
	GENERATED_BODY()
	
private:
	FTimerHandle AlphaTimerHandle;

public:	
	// Sets default values for this actor's properties
	ATimerActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	void AlphaTimerTick(); 
};
