// Fill out your copyright notice in the Description page of Project Settings.

#include "AssetActor.h"

#include <UObject/ConstructorHelpers.h>
// FObjectFinder, ...

#include <UObject/UObjectGlobals.h>
// FindObject, LoadObject

#include "Engine/Texture.h"
#include "Engine/Texture2D.h"

AAssetActor::AAssetActor()
{
	/** Inherited Properties */
	PrimaryActorTick.bCanEverTick = false;

	/** Asset Actor */

	// Find T_Alpha from T_ALPHA_REFERENCE 
	ConstructorHelpers::FObjectFinder<UTexture> AlphaTextureFinder(T_ALPHA_REFERENCE);
	if (AlphaTextureFinder.Succeeded())
	{
		UE_LOG(LogTemp, Warning, TEXT("Found T_Alpha as UTexture"));
		AlphaTexture = AlphaTextureFinder.Object;
	}
	
	// Find T_Alpha from T_ALPHA_REFERENCE_2 
	ConstructorHelpers::FObjectFinder<UTexture2D> AlphaTexture2DFinder(T_ALPHA_REFERENCE_2);
	if (AlphaTexture2DFinder.Succeeded())
	{
		UE_LOG(LogTemp, Warning, TEXT("Found T_Alpha as UTexture2D"));
		AlphaTexture2D = AlphaTexture2DFinder.Object;
	}
}

// Called when the game starts or when spawned
void AAssetActor::BeginPlay()
{
	Super::BeginPlay();

	BetaTexture2D = LoadObject<UTexture2D>(nullptr, T_ALPHA_REFERENCE);
}

// Called every frame
void AAssetActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

