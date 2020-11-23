// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class LearnSettings : ModuleRules
{
	public LearnSettings(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange( new string[] {
        });
		PrivateIncludePaths.AddRange( new string[] {
        });
			
		PublicDependencyModuleNames.AddRange( new string[] {
            "Core",
            "Settings",
            //      ISettingsModule #include "ISettingsModule.h"
        });
		PrivateDependencyModuleNames.AddRange( new string[] {
            "CoreUObject",
            "Engine",
            "Slate",
            "SlateCore",
        });
		
		DynamicallyLoadedModuleNames.AddRange( new string[] {
        });
	}
}
