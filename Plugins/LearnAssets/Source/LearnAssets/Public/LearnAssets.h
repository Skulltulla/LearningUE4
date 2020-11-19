// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "IAssetTypeActions.h"
//		IAssetTypeActions
#include "Modules/ModuleManager.h"

class FLearnAssetsModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	// See StartupModule, ShutdownModule
	TArray<TSharedPtr<IAssetTypeActions>> AssetTypeActions;
};
