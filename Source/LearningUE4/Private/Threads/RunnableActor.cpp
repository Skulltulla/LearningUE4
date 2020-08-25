// Fill out your copyright notice in the Description page of Project Settings.

#include "Threads/RunnableActor.h"

DEFINE_LOG_CATEGORY_STATIC(LogThreads, Warning, All)

FLoopRunnable::FLoopRunnable()
{
	UE_LOG(LogThreads, Warning, TEXT("FLoopRunnable()"));
}

FLoopRunnable::~FLoopRunnable()
{
	UE_LOG(LogThreads, Warning, TEXT("~FLoopRunnable()"));
	bLoop = false;
	if (pRunnableThread)
	{
		delete pRunnableThread;
		pRunnableThread = nullptr;
	}
}

bool FLoopRunnable::Init()
{
	UE_LOG(LogThreads, Warning, TEXT("FLoopRunnable()::Init()"));
	bLoop = true;
	return true;
}

uint32 FLoopRunnable::Run()
{
	UE_LOG(LogThreads, Warning, TEXT("FLoopRunnable()::Run()"));

	while (bLoop)
	{
		UE_LOG(LogThreads, Warning, TEXT("FLoopRunnable::Run() - tick"));
		FPlatformProcess::Sleep(1.f);
	}

	UE_LOG(LogThreads, Warning, TEXT("FLoopRunnable()::Run() - End"));
	return 0;
}

void FLoopRunnable::Stop()
{
	UE_LOG(LogThreads, Warning, TEXT("FLoopRunnable()::Stop()"));
	bLoop = false;

	// Something else may have forced the thread to stop
	if (pRunnableThread != nullptr)
	{
		delete pRunnableThread;
	}

	// todo
	// If delete is called from `Exit`, then Stop() immediately gets
	// called and nothing past `delete` gets executed, hence:
	pRunnableThread = nullptr;
}

void FLoopRunnable::Exit()
{
	UE_LOG(LogThreads, Warning, TEXT("FLoopRunnable()::Exit()"));

	if (pRunnableThread)
	{
		UE_LOG(LogThreads, Warning, TEXT("FLoopRunnable()::Exit() - deleting pRunnableThread"));

		// pRunnableThread->WaitForCompletion(); // todo: prevents Stop() from being executed after delete

		// Stop() immediately gets invoked after calling delete here and nothing after delete gets executed.
		// If WaitForCompletion is called before delete, then Stop() is not called
		delete pRunnableThread;

		// Does not get executed
		pRunnableThread = nullptr;
	}
}

void FLoopRunnable::StartRunnable()
{
	UE_LOG(LogThreads, Warning, TEXT("FLoopRunnable::Start()"));

	// When an instance of FRunnableThread is created, it will call the 
	// Runnable's Init() method and if it is successful, then it will 
	// call the Runnable's Run() method.
	if (pRunnableThread == nullptr)
	{
		UE_LOG(LogThreads, Warning, TEXT("FLoopRunnable::Start() - Creating runnable thread..."));
		pRunnableThread = FRunnableThread::Create(this, TEXT("FLoopRunnable"));
	}
}

void FLoopRunnable::StopRunnable()
{
	// The loop will stop, Run() will terminate, and then Exit() will get called.
	bLoop = false;
}

FLoopRunnable* FLoopRunnable::Create()
{
	UE_LOG(LogThreads, Warning, TEXT("Create()"));
	if (!FPlatformProcess::SupportsMultithreading())
	{
		UE_LOG(LogThreads, Warning, TEXT("FLoopRunnable::Create() - No multithreading support"));
		return nullptr;
	}

	UE_LOG(LogThreads, Warning, TEXT("FLoopRunnable()::Create() - Creating FLoopRunnable()"));
	FLoopRunnable* LoopRunnablePtr = new FLoopRunnable();
	return LoopRunnablePtr;
}

// Sets default values
ARunnableActor::ARunnableActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ARunnableActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ARunnableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ARunnableActor::StartRunnable()
{
	if (LoopRunnablePtr == nullptr)
	{
		LoopRunnablePtr = FLoopRunnable::Create();
	}
	LoopRunnablePtr->StartRunnable();
}

void ARunnableActor::StopRunnable()
{
	if (LoopRunnablePtr)
	{
		LoopRunnablePtr->StopRunnable();
	}
}

