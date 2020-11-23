#pragma once

#include "CoreMinimal.h"
#include "LearnSettingsSettings.generated.h"

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

	ULearnSettingsSettings();
};
