// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DelegateActor.generated.h"


DECLARE_DELEGATE(/** typename */ FAlphaDelegate)

UCLASS()
class LEARNINGUE4_API ADelegateActor : public AActor
{
	GENERATED_BODY()

private:

	// See constructor for bindings
	FAlphaDelegate AlphaDelegate_Lambda;
	FAlphaDelegate AlphaDelegate_Raw;
	FAlphaDelegate AlphaDelegate_SP;
	FAlphaDelegate AlphaDelegate_Static;
	FAlphaDelegate AlphaDelegate_ThreadSafeSP;
	FAlphaDelegate AlphaDelegate_UFunction;
	FAlphaDelegate AlphaDelegate_UObject;

	void AlphaRawCallback()
	{
		UE_LOG(LogTemp, Warning, TEXT("ADelegateActor::AlphaRawCallback()"));
	}

	void AlphaUObjectCallback()
	{
		UE_LOG(LogTemp, Warning, TEXT("ADelegateActor::AlphaUObjectCallback()"));
	}

public:	
	// Sets default values for this actor's properties
	ADelegateActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
