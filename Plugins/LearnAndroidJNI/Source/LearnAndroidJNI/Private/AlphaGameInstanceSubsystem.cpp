// Fill out your copyright notice in the Description page of Project Settings.

#include "AlphaGameInstanceSubsystem.h"

#if PLATFORM_ANDROID
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"
#include "jni.h"
#endif

DEFINE_LOG_CATEGORY(LogAndroidJNI)

bool UAlphaGameInstanceSubsystem::ShouldCreateSubsystem(UObject* Outer) const 
{
	return true;
}

void UAlphaGameInstanceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
#if PLATFORM_ANDROID
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	if (!Env)
	{
		UE_LOG(LogAndroidJNI, Error, TEXT("UAlphaGameInstanceSubsystem::Initialize() - JNIEnv is null"));
		return;
	}
#endif
}

void UAlphaGameInstanceSubsystem::Deinitialize()
{
}
