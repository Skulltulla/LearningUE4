// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class LearnAssets : ModuleRules
{
	public LearnAssets(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange( new string[] {
		});
		PrivateIncludePaths.AddRange( new string[] {
		});
			
		PublicDependencyModuleNames.AddRange( new string[] {
			"AssetTools",
			// #include "AssetTypeCategories.h"
			//		EAssetTypeCategories 
			
			"Core",
			
			"UnrealEd"
			// #include "Factories/Factory.h"
			//		UFactory
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
