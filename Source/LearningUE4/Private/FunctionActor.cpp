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
	
	// Invoking "Event Lambda" from C++
	// "Event Lambda" is in BP_FunctionActor with a print string node
	Lambda();

	// Invoking the overridable function in blueprint
	Mu();

	// Invoking the overridable function in blueprint, but this one returns something
	bool bNu;
	Nu(bNu);
}

// Called every frame
void AFunctionActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


