// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class LearningUE4 : ModuleRules
{
	public LearningUE4(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		/** Default */
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });
		PublicDependencyModuleNames.AddRange(new string[] { });

		PrivateDependencyModuleNames.AddRange(new string[] { });
	}
}
