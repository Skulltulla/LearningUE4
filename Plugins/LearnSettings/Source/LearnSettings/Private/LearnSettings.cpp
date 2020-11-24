// Copyright Epic Games, Inc. All Rights Reserved.

#include "LearnSettings.h"
#include "LearnSettingsSettings.h"
#if WITH_EDITOR
#include "ISettingsModule.h"
#endif

#define LOCTEXT_NAMESPACE "FLearnSettingsModule"

const FName NAME_PROJECT = FName(TEXT("Project")); // for project settings
const FName NAME_EDITOR = FName(TEXT("Editor")); // for editor preferences, e.g. Flipbook Editor under Content Editors from Paper2D
const FName NAME_PLUGIN = FName(TEXT("Plugin"));
const FName NAME_LEARNSETTINGS = FName(TEXT("LearnSettings"));
const FText TEXT_SETTINGS_TITLE = LOCTEXT("LEARN_SETTINGS_NAME", "LearnSettings Settings");
const FText TEXT_SETTINGS_DESCRIPTION = LOCTEXT("LEARN_SETTINGS_DESCRIPTION", "Configure settings for this plugin.");

void FLearnSettingsModule::StartupModule()
{
	RegisterToProjectSettings();
}

void FLearnSettingsModule::ShutdownModule()
{
	UnregisterFromProjectSettings();
}

void FLearnSettingsModule::RegisterToProjectSettings()
{
#if WITH_EDITOR
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");
	if (SettingsModule)
	{
		SettingsModule->RegisterSettings(
			NAME_PROJECT, 
			NAME_PLUGIN, 
			NAME_LEARNSETTINGS, 
			TEXT_SETTINGS_TITLE, 
			TEXT_SETTINGS_DESCRIPTION, 
			GetMutableDefault<ULearnSettingsSettings>());
	}
#endif
}

void FLearnSettingsModule::UnregisterFromProjectSettings()
{
#if WITH_EDITOR
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");
	if (SettingsModule)
	{
		SettingsModule->UnregisterSettings(NAME_PROJECT, NAME_PLUGIN, NAME_LEARNSETTINGS);
	}
#endif
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FLearnSettingsModule, LearnSettings)