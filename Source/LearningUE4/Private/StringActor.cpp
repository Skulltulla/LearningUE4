// Fill out your copyright notice in the Description page of Project Settings.

#include "StringActor.h"

// Sets default values
AStringActor::AStringActor()
{
	/** Inherited Properties */
	PrimaryActorTick.bCanEverTick = true;

	/** String Actor */

	// todo
	FString AlphaFString = FString(TEXT("AlphaFString"));
	AlphaFString = FString("AlphaFString"); 
	AlphaFString = "AlphaFString"; 
	AlphaFString = TEXT("AlphaFString");
	UE_LOG(LogTemp, Warning, TEXT("%s"), *AlphaFString);	// *AlphaFString -> TCHAR*

	// todo
	FString BetaFString = AlphaFString;

	// todo
	AlphaFString = AlphaFString + AlphaFString;
	AlphaFString = AlphaFString + "AlphaFString";
	AlphaFString += "AlphaFString";
	AlphaFString += FString(TEXT("GammaFString"));
	AlphaFString += TEXT("GammaFString");

	bool bAlpha = (AlphaFString == AlphaFString); 
}

// Called when the game starts or when spawned
void AStringActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AStringActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

