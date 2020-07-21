// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AlphaGameInstanceSubsystem.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogAndroidJNI, Warning, All)

/**
 *
 */
UCLASS()
class LEARNANDROIDJNI_API UAlphaGameInstanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	/** USubsystem Interface */
	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	virtual void Deinitialize() override;
};
