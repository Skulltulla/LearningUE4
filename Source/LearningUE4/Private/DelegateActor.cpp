// Fill out your copyright notice in the Description page of Project Settings.


#include "DelegateActor.h"

// Sets default values
ADelegateActor::ADelegateActor()
{
	/** Inherited Properties */
	PrimaryActorTick.bCanEverTick = true;

	/** Delegate Actor */
	AlphaDelegate_Lambda.BindLambda([]() {
		UE_LOG(LogTemp, Warning, TEXT("AlphaDelegate.BindLambda()"));
	});

	AlphaDelegate_UObject.BindUObject(this, &ADelegateActor::AlphaUObjectCallback);
}

// Called when the game starts or when spawned
void ADelegateActor::BeginPlay()
{
	Super::BeginPlay();

	if (AlphaDelegate_Lambda.IsBound())
	{
		AlphaDelegate_Lambda.Execute();
	}

	bool bAlphaRaw = AlphaDelegate_Raw.ExecuteIfBound();
	bool bAlphaUObject = AlphaDelegate_UObject.ExecuteIfBound();
}

// Called every frame
void ADelegateActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

