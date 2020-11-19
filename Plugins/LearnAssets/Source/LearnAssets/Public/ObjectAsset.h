// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ObjectAsset.generated.h"

/**
 * A new asset type that inherits directly from UObject.
 *
 * See StartupModule, ShutdownModule, ObjectAssetFactory
 */
UCLASS()
class LEARNASSETS_API UObjectAsset : public UObject
{
	GENERATED_BODY()
	
public:

protected:
    UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "LearnAssets")
    FString Content;
    
private:
};
