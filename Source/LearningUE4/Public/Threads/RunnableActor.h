// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HAL/Runnable.h"
#include "HAL/RunnableThread.h"
#include "RunnableActor.generated.h"

/**
 *  HAL/Runnable.h
 *  HAL/RunnableThread.h
 */
class FLoopRunnable : public FRunnable
{
private:
	// The thread to run this runnable on. (See FRunnableThread)
	FRunnableThread* pRunnableThread = nullptr;

	// Enabled in Init(), disabled in Stop(), and used in Run()
	bool bLoop = false;

	// Use FLoopRunnable::Create()
	FLoopRunnable();

public:
	~FLoopRunnable();

public:
	/** FRunnable Interface */

	// Do not explicitly call this
	// it will automatically be invoked when an instance of pRunnableThread is created
	virtual bool Init();

	// Do not explicitly call this
	// it will automatically be invoked if Init() was successful.
	virtual uint32 Run();

	// Do not explicitly call this - thread early termination
	virtual void Stop();

	// Do not expicitly call this
	// it will automatically be invoked after Run() returns.
	virtual void Exit();

public:
	/** FLoopRunnable Interface */

	// Create an instance of FLoopRunnable. Use Start() to run it.
	// @return - nullptr if multithreading is not supported
	static FLoopRunnable* Create();

	// Start the thread by creating an instance of pRunnableThread 
	void StartRunnable();

	// todo
	// Stops the runnable by disabling bLoop, then Exit() will delete the thread
	// and then Stop() will invalidate it.
	void StopRunnable();
};

UCLASS()
class LEARNINGUE4_API ARunnableActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARunnableActor();

	~ARunnableActor()
	{
		if (pLoopRunnable)
		{
			pLoopRunnable->StopRunnable(); 
			// delete pLoopRunnable;
		}
	}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UFUNCTION(BlueprintCallable, Category = "LearningUE4 | Threads")
	void StartRunnable();

	UFUNCTION(BlueprintCallable, Category = "LearningUE4 | Threads")
	void StopRunnable();

private:
	FLoopRunnable* pLoopRunnable = nullptr;
};
