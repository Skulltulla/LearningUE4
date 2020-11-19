// Fill out your copyright notice in the Description page of Project Settings.

#include "ObjectAssetFactory.h"
#include "ObjectAsset.h"
#include "AssetTypeCategories.h"

UObjectAssetFactory::UObjectAssetFactory()
{
    SupportedClass = UObjectAsset::StaticClass();
}

FText UObjectAssetFactory::GetDisplayName() const
{
    return FText::FromString("Object Asset Display Name");
}

UObject* UObjectAssetFactory::FactoryCreateNew(
    UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
    UObjectAsset* NewObjectAsset = NewObject<UObjectAsset>(InParent, InClass, InName, Flags );
    return NewObjectAsset;
}

bool UObjectAssetFactory::ShouldShowInNewMenu() const
{
    return true;
}

uint32 UObjectAssetFactory::GetMenuCategories() const
{
    // @None - Does not appear in context menu
    return EAssetTypeCategories::Misc;
}

// ---------------------------------------------------------------------------------------------------- 

FText FAssetTypeActions_ObjectAsset ::GetName() const
{
    return FText::FromString("ObjectAsset");
}

FColor FAssetTypeActions_ObjectAsset ::GetTypeColor() const
{
    return FColor::Blue;
}

UClass* FAssetTypeActions_ObjectAsset ::GetSupportedClass() const
{
    return UObjectAsset::StaticClass();
}

uint32 FAssetTypeActions_ObjectAsset::GetCategories()
{
    return EAssetTypeCategories::None;
}


