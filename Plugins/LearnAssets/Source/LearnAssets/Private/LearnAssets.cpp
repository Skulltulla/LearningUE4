/**
 * REFERENCES:
 * [1] "Writing a custom asset editor for unreal engine 4 - part 2" [Online] Available:
 * 		http://www.cairansteverink.nl/cairansteverink/blog/writing-a-custom-asset-editor-for-unreal-engine-4-part-2/
 */
#include "LearnAssets.h"

#include "AssetToolsModule.h"
//		FAssetToolsModule
#include "IAssetTools.h"
//		IAssetTools
#include "ObjectAssetFactory.h"
//		FAssetTypeActions_ObjectAsset

#define LOCTEXT_NAMESPACE "FLearnAssetsModule"

void FLearnAssetsModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	// Register FAssetTypeActions_ObjectAsset with the AssetTools module so we may
	// create a new instance of the asset in the Context Menu.
	// references: [1]
	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
	const TSharedRef<IAssetTypeActions> AssetAction = MakeShareable(new FAssetTypeActions_ObjectAsset());
	AssetTools.RegisterAssetTypeActions(AssetAction);
	AssetTypeActions.Add(AssetAction);
}

void FLearnAssetsModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	// REFERENCE: [1]
	if(FModuleManager::Get().IsModuleLoaded("AssetTools"))
	{
		IAssetTools& AssetTools = FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools").Get();
		for( auto& AssetAction : AssetTypeActions )
		{
			AssetTools.UnregisterAssetTypeActions( AssetAction.ToSharedRef() );
		}
	}
	AssetTypeActions.Empty();
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FLearnAssetsModule, LearnAssets)