#pragma once

#include "Engine/DataTable.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/ConfigCacheIni.h"
//        Module: Core
//        GConfig
//        ** Filename FStrings **
//        GEngineIni
//        GEditorIni
//        GEditorSettingsIni
//        GGameIni
//        ...
#include "LearnSettingsBPLibrary.generated.h"

UCLASS()
class LEARNSETTINGS_API ULearnSettingsBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Alpha"), Category = "LearnSettings")
	static bool GetAlpha();

	/**
	 * Uses GConfig to retrieve the asset's reference and StaticLoadObject to load it.
	 * 
	 * Note: FObjectFinder is part of ConstructorHelpers and can only be used in the construction script.
	 * 
	 * Reading:
	 * - https://answers.unrealengine.com/questions/2601/dynamic-load-object.html?sort=oldest
	 * - https://forums.unrealengine.com/development-discussion/c-gameplay-programming/58117-unloading-a-umaterial-and-understanding-staticloadobject
	 * - https://answers.unrealengine.com/questions/769991/fobjectfinder-vs-loadobject.html?sort=oldest
	 */
	UFUNCTION(BlueprintCallable, meta=(DisplayName=""), Category="LearnSettings")
	static UDataTable* LoadAlphaDataTable();

private:
	static FString GetObjectReferenceString(const TCHAR* Section, const TCHAR* Key, const FString& Filename);
};
