#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "LearnSettingsBPLibrary.generated.h"

UCLASS()
class LEARNSETTINGS_API ULearnSettingsBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	// UFUNCTION(BlueprintCallable, meta = (DisplayName = "Execute Sample function", Keywords = "EmptyBPLibrary sample test testing"), Category = "EmptyBPLibraryTesting")
	// static float EmptyBPLibrarySampleFunction(float Param);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Alpha"), Category = "LearnSettings")
	static bool GetAlpha();
};
