// Fill out your copyright notice in the Description page of Project Settings.


#include "FunctionActor.h"
#include "..\Public\FunctionActor.h"

// Sets default values
AFunctionActor::AFunctionActor()
{
	/** Inherited Properties */
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/** Function Actor */
}

AFunctionActor::~AFunctionActor()
{
}

// Called when the game starts or when spawned
void AFunctionActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AFunctionActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


