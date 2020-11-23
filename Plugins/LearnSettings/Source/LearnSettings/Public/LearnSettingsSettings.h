#pragma once

#include "CoreMinimal.h"
#include "LearnSettingsSettings.generated.h"

class UDataTable; // #include "Engine/DataTable.h"

/**
 Settings for the LearnSettings plugin.

 @Config
 https://docs.unrealengine.com/en-US/Programming/UnrealArchitecture/Reference/Classes/Specifiers/index.html

 @defaultconfig
 https://docs.unrealengine.com/en-US/API/Runtime/CoreUObject/UObject/UC/index.html
 */
UCLASS(config=Game, defaultconfig, meta=(DisplayName="Learn Setting's Settings"))
class LEARNSETTINGS_API ULearnSettingsSettings : public UObject
{
	GENERATED_BODY()
	
public:
	/**
	 * @config
	 * https://docs.unrealengine.com/en-US/API/Runtime/CoreUObject/UObject/UC/index.html
	 */
	UPROPERTY(config, EditAnywhere, Category="Data")
	bool bAlpha;

	/**
	 * Invalid:
	 * Cannot use `config` with UObjects. Dynamically load the object, etc.
	 * https://answers.unrealengine.com/questions/2601/dynamic-load-object.html?sort=oldest
	 */
	// UPROPERTY(config, EditAnywhere, Category="Data")
	// UObject* AlphaObject;

	/**
	 * Stores a soft reference to a UDataTable object so it may be loaded later.
	 *
	 * 
	 */
	// Store a reference to the object so it may be loaded later
	// GConfig->GetStr is used to get its reference, i.e. '/Alpha/Beta/DT_DebugQuiz.DT_DebugQuiz'
	UPROPERTY(config, EditAnywhere, Category="Data")
	TSoftObjectPtr<UDataTable> AlphaDataTable;
	
	ULearnSettingsSettings();
};
