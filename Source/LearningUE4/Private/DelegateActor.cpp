// Fill out your copyright notice in the Description page of Project Settings.


#include "DelegateActor.h"

// Sets default values
ADelegateActor::ADelegateActor()
{
	/** Inherited Properties */
	PrimaryActorTick.bCanEverTick = true;

	/** Delegate Actor */
	AlphaDelegate_Lambda.BindLambda([]() {
		UE_LOG(LogTemp, Warning, TEXT("ADelegateActor::AlphaLambdaCallback()"));
	});

	// todo
	/** Invalid : You cannot use raw method delegates with UObjects  */
	// AlphaDelegate_Raw.BindRaw(this, &ADelegateActor::AlphaRawCallback);
	AlphaDelegate_Static.BindStatic(&ADelegateActor::AlphaStaticCallback);
	AlphaDelegate_UFunction.BindUFunction(this, FName("AlphaUFunctionCallback"));
	AlphaDelegate_UObject.BindUObject(this, &ADelegateActor::AlphaUObjectCallback);

	// todo
	// AlphaMulticastDelegate_Simple.Add()
	// AlphaMulticastDelegate_Lambda.AddLambda();
	// AlphaMulticastDelegate_Raw.AddRaw();
	// AlphaMulticastDelegate_SP.AddSP();
	// AlphaMulticastDelegate_Static.AddStatic();
	// AlphaMulticastDelegate_ThreadSafeSP.AddThreadSafeSP();
	// AlphaMulticastDelegate_UFunction.AddUFunction();
	// AlphaMulticastDelegate_UObject.AddUObject();

	AlphaDynamicDelegate.BindUFunction(this, FName("AlphaDynamicCallback"));

	FScriptDelegate AlphaScriptDelegate; // todo : may not want this to be local
	AlphaScriptDelegate.BindUFunction(this, FName("AlphaDynamicMulticastCallback"));
	AlphaDynamicMulticastDelegate.AddUnique(AlphaScriptDelegate);
}

ADelegateActor::~ADelegateActor()
{
}

// Called when the game starts or when spawned
void ADelegateActor::BeginPlay()
{
	Super::BeginPlay();

	if (AlphaDelegate_Lambda.IsBound())
	{
		AlphaDelegate_Lambda.Execute();
	}

	bool bAlpha = AlphaDelegate_Raw.ExecuteIfBound();
	bAlpha = AlphaDelegate_UObject.ExecuteIfBound();
	bAlpha = AlphaDelegate_UFunction.ExecuteIfBound();
	bAlpha = AlphaDelegate_Static.ExecuteIfBound();

	AlphaDynamicDelegate.ExecuteIfBound();

	AlphaDynamicMulticastDelegate.Broadcast();
}

void ADelegateActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
}

// Called every frame
void ADelegateActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

