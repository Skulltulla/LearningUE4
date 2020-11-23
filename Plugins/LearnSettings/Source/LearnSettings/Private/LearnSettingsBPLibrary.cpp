#include "LearnSettingsBPLibrary.h"
#include "Misc/ConfigCacheIni.h"
//        Module: Core
//        GConfig
//        ** Filename FStrings **
//        GEngineIni
//        GEditorIni
//        GEditorSettingsIni
//        GGameIni
//        ...

/** See DefaultGame.ini */
// TODO: Omitting `/Script/` crashes with "Short config section used instead of long LearnSettings.LearnSettingsSettings"
#define TEXT_SECTION_NAME TEXT("/Script/LearnSettings.LearnSettingsSettings") 
#define TEXT_KEY_BALPHA TEXT("bAlpha")
#define TEXT_KEY_ALPHADT TEXT("AlphaDataTable")

ULearnSettingsBPLibrary::ULearnSettingsBPLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

bool ULearnSettingsBPLibrary::GetAlpha()
{
    bool bAlpha;
    if(GConfig->GetBool( TEXT_SECTION_NAME, TEXT_KEY_BALPHA, bAlpha, GGameIni))
    {
        UE_LOG(LogTemp, Error, TEXT("bAlpha: %d"), bAlpha);
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to read bAlpha"));
    }
    return bAlpha;
}

UDataTable* ULearnSettingsBPLibrary::LoadAlphaDataTable()
{
	const FString ReferenceString = GetObjectReferenceString(TEXT_SECTION_NAME, TEXT_KEY_ALPHADT, GGameIni);
    if( ReferenceString.IsEmpty() )
    {
        return nullptr;
    }
	return Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(), nullptr, *ReferenceString));
}

FString ULearnSettingsBPLibrary::GetObjectReferenceString(const TCHAR* Section, const TCHAR* Key, const FString& Filename)
{
    // If the object is not assigned, then the returned string will be empty;
    // otherwise, it will contain a reference, i.e. `/Alpha/Beta/MyDataTable.MyDataTable`
    return GConfig->GetStr(Section, Key, Filename);
}
