// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "AlphaGameInstance.generated.h"

/** 
 * Alpha Game Instance
 * 
 * - Create a blueprint subclass 
 *   - Project Settings > Maps & Modes > Game Instance Class
 *   - Implement the Events
 *     - Init
 *     - Shutdown
 *     - NetworkError
 *     - TravelError
 */
UCLASS()
class LEARNINGUE4_API UAlphaGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:

};
