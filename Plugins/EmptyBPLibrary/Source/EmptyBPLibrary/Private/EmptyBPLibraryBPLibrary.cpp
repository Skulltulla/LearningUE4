// Copyright Epic Games, Inc. All Rights Reserved.

#include "EmptyBPLibraryBPLibrary.h"
#include "EmptyBPLibrary.h"

UEmptyBPLibraryBPLibrary::UEmptyBPLibraryBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

float UEmptyBPLibraryBPLibrary::EmptyBPLibrarySampleFunction(float Param)
{
	return -1;
}

