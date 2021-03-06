// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AssetActor.generated.h"

class UTexture;				// Module: Engine | #include "Engine/Texture.h"
class UTexture2D;			// Module: Engine | #include "Engine/Texture2D.h"

// The first reference was generated by right-clicking on T_Alpha in the editor and selecting "Copy Reference"
// NOTE: If you hover over T_Alpha in the Content Browser it says 'Texture' as the asset type.
// NOTE: Valid alternative references listed below
const TCHAR T_ALPHA_REFERENCE[] = TEXT("Texture2D'/Game/Textures/T_Alpha.T_Alpha'");
const TCHAR T_ALPHA_REFERENCE_2[] = TEXT("/Game/Textures/T_Alpha.T_Alpha");
const TCHAR T_ALPHA_REFERENCE_3[] = TEXT("/Game/Textures/T_Alpha");

UCLASS()
class LEARNINGUE4_API AAssetActor : public AActor
{
	GENERATED_BODY()
	
public:

	// REFERENCES: Texture2D'/Game/Textures/T_Alpha.T_Alpha'
	UPROPERTY(VisibleAnywhere, Category = "LearningUE4 | Assets")
	UTexture* AlphaTexture = nullptr;

	// REFERENCES: Texture2D'/Game/Textures/T_Alpha.T_Alpha'
	UPROPERTY(VisibleAnywhere, Category = "LearningUE4 | Assets")
	UTexture2D* AlphaTexture2D = nullptr;

	// REFERENCES: Texture2D'/Game/Textures/T_Alpha.T_Alpha'
	UPROPERTY(VisibleAnywhere, Category = "LearningUE4 | Assets")
	UTexture2D* BetaTexture2D = nullptr;

public:	
	// Sets default values for this actor's properties
	// Hit the blueprint compile button in the BP_AssetActor to manually invoke
	AAssetActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
