// Fill out your copyright notice in the Description page of Project Settings.

#include "TimerActor.h"
#include "Engine/World.h"
#include "TimerManager.h"

DEFINE_LOG_CATEGORY_STATIC(/** Name */ LogTimerActor, /** Default */ Warning, /** CompileTime */ All)

// Sets default values
ATimerActor::ATimerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ATimerActor::BeginPlay()
{
	Super::BeginPlay();

	// WARNING: `const` will prevent timers from being set
	const FTimerManager& AlphaWorldTimerManager = GetWorldTimerManager();
	FTimerManager& BetaWorldTimerManager = GetWorldTimerManager();

	// Simple Set Timer
	BetaWorldTimerManager.SetTimer(AlphaTimerHandle, /** UserClass */ this, &ATimerActor::AlphaTimerTick, /** seconds */ 5.f, /** loop */ false);
}

// Called every frame
void ATimerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const float AlphaTimerRemainingTime = GetWorldTimerManager().GetTimerRemaining(AlphaTimerHandle);
	const float AlphaTimerElapsedTime = GetWorldTimerManager().GetTimerElapsed(AlphaTimerHandle);
}

void ATimerActor::AlphaTimerTick()
{
	UE_LOG(LogTimerActor, Warning, TEXT("ATimerActor::AlphaTimerTick()"));
}

