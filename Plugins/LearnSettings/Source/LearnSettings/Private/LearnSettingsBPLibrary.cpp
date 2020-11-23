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
