// Fill out your copyright notice in the Description page of Project Settings.

#include "StringActor.h"

// Sets default values
AStringActor::AStringActor()
{
	/** Inherited Properties */
	PrimaryActorTick.bCanEverTick = true;

	/** String Actor */

	// todo
	// NOTE: I'm not sure if it is recommended to use wchar_t directly; it's not in the documentation
	const wchar_t AlphaTEXT[] = TEXT("AlphaTEXT");
	// const wchar_t[] AlphaTEXT = TEXT("AlphaTEXT"); // invalid syntax 
	UE_LOG(LogTemp, Warning, AlphaTEXT);

	const wchar_t BetaTEXT[9] = TEXT("BetaTEXT"); // [n] = len("")+1
	UE_LOG(LogTemp, Warning, BetaTEXT);

	const wchar_t GammaTEXT[10] = { TEXT("GammaTEXT") }; // [n] = len("")+1
	// const wchar_t GammaTEXT[2] = { TEXT("Gamma"), TEXT("TEXT") }; // invalid syntax - not equivalent to initializing string[]
	UE_LOG(LogTemp, Warning, GammaTEXT);

	// todo
	// NOTE: I'm not sure if it is recommended to use TCHAR directly; it's not in the documentation
	const TCHAR DeltaTEXT[12] = TEXT("DeltaTEXT");
	UE_LOG(LogTemp, Warning, DeltaTEXT);

	const TCHAR EpsilonTEXT[] = TEXT("EpsilonTEXT");
	UE_LOG(LogTemp, Warning, EpsilonTEXT);

	// todo
	FString AlphaFString = FString(TEXT("AlphaFString"));
	AlphaFString = FString("AlphaFString"); 
	AlphaFString = "AlphaFString"; 
	AlphaFString = TEXT("AlphaFString");
	UE_LOG(LogTemp, Warning, TEXT("%s"), *AlphaFString); // *AlphaFString -> TCHAR*

	// todo
	FString BetaFString = AlphaFString;

	// todo
	AlphaFString = AlphaFString + AlphaFString;
	AlphaFString = AlphaFString + "AlphaFString";
	AlphaFString += "AlphaFString";
	AlphaFString += FString(TEXT("GammaFString"));
	AlphaFString += TEXT("GammaFString");

	bool bAlpha = (AlphaFString == AlphaFString); 
}

// Called when the game starts or when spawned
void AStringActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AStringActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

