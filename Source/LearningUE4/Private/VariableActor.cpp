// Fill out your copyright notice in the Description page of Project Settings.

#include "VariableActor.h"

// Sets default values
AVariableActor::AVariableActor() :
	bAlpha(false) 
{
	/** Inherited Properties */
	PrimaryActorTick.bCanEverTick = false;

	/** VariableActor */
	this->bBeta = false;
}

// Called when the game starts or when spawned
void AVariableActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AVariableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AVariableActor::PostInitProperties()
{
	Super::PostInitProperties(); // Warning: without this, the editor will crash upon launch
	UpdateDependentVariables();
}

#if WITH_EDITOR
void AVariableActor::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	UpdateDependentVariables();
	Super::PostEditChangeProperty(PropertyChangedEvent);
}
#endif

void AVariableActor::UpdateDependentVariables()
{
	bIota = !bTheta;
}

