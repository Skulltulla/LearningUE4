// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FLearnSettingsModule : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	// This code will execute after your module is loaded into memory;
	// the exact timing is specified in the .uplugin file per-module
	virtual void StartupModule() override;
	
	// This function may be called during shutdown to clean up your module.
	// For modules that support dynamic reloading, we call this function before unloading the module.
	virtual void ShutdownModule() override;

private:
	/** Settings Interface */
	// Uses ISettingsModule to register to project settings
	void RegisterToProjectSettings();

	// Uses ISettingsModule to unregister from project settings
	void UnregisterFromProjectSettings();
};
