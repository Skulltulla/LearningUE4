/**
 * References
 * 
 * [1] Eleftheriou, Orfeas. "Creating Custom Editor Assets" [Online]. Available:
 * 		https://www.orfeasel.com/creating-custom-editor-assets/
 * 		> This article demonstrated created a subclass of UFactory
 * 		
 * [2] Steverink, Cairan. "Writing a custom asset editor for unreal engine 4 - part 2". Available:
 * 		http://www.cairansteverink.nl/cairansteverink/blog/writing-a-custom-asset-editor-for-unreal-engine-4-part-2/
 * 		> This article demonstrated created a subclass of FAssetTypeActions_Base
 */

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
//		UFactory
#include "AssetTypeActions_Base.h"
//		FAssetTypeActions_Base
#include "ObjectAssetFactory.generated.h"

/**
 * Modules: UnrealEd
 *
 * References: [1]
 */
UCLASS()
class LEARNASSETS_API UObjectAssetFactory : public UFactory
{
	GENERATED_BODY()

public:

	UObjectAssetFactory();

	/**
	 * UFactory Interface
	 */
	// What appears in menus, e.g. Context Menu
	virtual FText GetDisplayName() const override;

	// Create a new instance of the object
	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;

	// For New Asset menu
	virtual bool ShouldShowInNewMenu() const override;

	// @return EAssetTypeCategories
	virtual uint32 GetMenuCategories() const override;
};

/**
 * REFERENCES: [2]
 */
class FAssetTypeActions_ObjectAsset : public FAssetTypeActions_Base
{
public:
	// The text that will appear in parenthesis after the asset name, e.g Blueprint, Texture2D;
	// it will also appear in the asset's box in the Content Browser.
	virtual FText GetName() const override;

	// The background color of the box
	virtual FColor GetTypeColor() const override;

	// The class a new asset will be created from
	virtual UClass* GetSupportedClass() const override;

	virtual uint32 GetCategories() override;
};

