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
	const wchar_t AlphaWCHART = 'a';
	const wchar_t BetaWCHART = 'b';
	const wchar_t GammaWCHART = 'A';
	UE_LOG(LogTemp, Warning, TEXT("%c"), AlphaWCHART);

	bool bWCHART;
	bWCHART = (AlphaWCHART == AlphaWCHART);  // true
	bWCHART = (AlphaWCHART == BetaWCHART);   // false
	bWCHART = (AlphaWCHART == GammaWCHART);  // false

#if !PLATFORM_ANDROID
	// TODO
	// Error: Initializing wide char array with incompatible wide string literal
	const wchar_t AlphaTEXT[] = TEXT("AlphaTEXT");
	UE_LOG(LogTemp, Warning, AlphaTEXT);
	
	const wchar_t BetaTEXT[9] = TEXT("BetaTEXT"); // [n] = len("")+1

	// TODO
	// ERROR: Cannot initialize an array element of type 'const wchar_t' with
	// an lvalue of type 'const char16_t [10]'
	const wchar_t GammaTEXT[10] = { TEXT("GammaTEXT") };
#endif
	
	// Invalid syntax - not equivalent to initializing string[]
	// const wchar_t GammaTEXT[2] = { TEXT("Gamma"), TEXT("TEXT") }; 

	// TODO
	// NOTE: I'm not sure if it is recommended to use TCHAR directly; it's not in the documentation
	const TCHAR AlphaTCHAR = 'a';
	const TCHAR BetaTCHAR = 'b';
	const TCHAR GammaTCHAR = 'A';
	UE_LOG(LogTemp, Warning, TEXT("%c"), AlphaTCHAR);
	
	bool bTCHAR;
	bTCHAR = (AlphaTCHAR == AlphaTCHAR);	// true
	bTCHAR = (AlphaTCHAR == BetaTCHAR);		// false
	bTCHAR = (AlphaTCHAR == GammaTCHAR);	// false

	const TCHAR DeltaTEXT[] = TEXT("DeltaTEXT");
	const TCHAR EpsilonTEXT[12] = TEXT("EpsilonTEXT");
	const TCHAR ZetaTEXT[9] = { TEXT("ZetaTEXT") };
	UE_LOG(LogTemp, Warning, DeltaTEXT);

	// todo
	FString AlphaFString;
	AlphaFString = "AlphaFString"; 
	AlphaFString = TEXT("AlphaFString");
	AlphaFString = FString("AlphaFString"); 
	AlphaFString = FString(TEXT("AlphaFString"));
	FString BetaFString = AlphaFString;
	UE_LOG(LogTemp, Warning, TEXT("%s"), *AlphaFString); // *FString -> TCHAR*

	// todo
	AlphaFString += "AlphaFString";
	AlphaFString += TEXT("GammaFString");
	AlphaFString += FString(TEXT("GammaFString"));
	AlphaFString += AlphaFString;

	int32 AlphaInt32;
	AlphaInt32 = AlphaFString.Len();

	// todo
	// Equals - case-sensitive by default
	bool bAlpha;
	bAlpha = FString(TEXT("a")) == FString(TEXT("a"));		// true
	bAlpha = FString(TEXT("a")).Equals(FString(TEXT("a")));	// true

	bAlpha = FString(TEXT("a")) == FString(TEXT("A"));		// true
	bAlpha = FString(TEXT("a")).Equals(FString(TEXT("A")));	// false

	bAlpha = FString(TEXT("a")) == FString(TEXT("b"));		// false
	bAlpha = FString(TEXT("a")).Equals(FString(TEXT("b")));	// false

	// todo
	// Compare - case-sensitive by default
	// A = U+0041	B = U+0042	Z = U+005A
	// a = U+0061	b = U+0062	z = U+007A
	AlphaInt32 = FString(TEXT("a")).Compare(FString(TEXT("a")));	// 0
	AlphaInt32 = FString(TEXT("b")).Compare(FString(TEXT("a")));	// 1
	AlphaInt32 = FString(TEXT("a")).Compare(FString(TEXT("b")));	// -1
	AlphaInt32 = FString(TEXT("a")).Compare(FString(TEXT("A")));	// 1
	AlphaInt32 = FString(TEXT("A")).Compare(FString(TEXT("a")));	// -1
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

