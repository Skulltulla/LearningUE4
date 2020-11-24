// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class LearnSettings : ModuleRules
{
	public LearnSettings(ReadOnlyTargetRules Target) : base(Target)
	{
		//
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		//
		bool IsTargetTypeEditor = Target.Type == TargetRules.TargetType.Editor;
		
		//
		PublicIncludePaths.AddRange( new string[] {
        });
		PrivateIncludePaths.AddRange( new string[] {
        });
			
		//
		PublicDependencyModuleNames.AddRange( new string[] {
            "Core",
        });
		if (IsTargetTypeEditor)
		{
			PrivateDependencyModuleNames.AddRange(new string[]
			{
				"Settings",
				//	ISettingsModule (LearnSettings)
			});
		}
		PrivateDependencyModuleNames.AddRange( new string[] {
            "CoreUObject",
            "Engine",
            "Slate",
            "SlateCore",
        });
		
		//
		DynamicallyLoadedModuleNames.AddRange( new string[] {
        });
	}
}
