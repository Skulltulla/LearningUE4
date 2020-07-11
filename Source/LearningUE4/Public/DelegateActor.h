// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DelegateActor.generated.h"

/**
 * # Delegate
 */
DECLARE_DELEGATE(/** typename */ FAlphaDelegate)
DECLARE_DELEGATE_OneParam(FBetaDelegate, /** param type */ bool)
// _TwoParams, _ThreeParams, _FourParams, _FiveParams, _SixParams, _SevenParams, _EightParams, _NineParams

DECLARE_DELEGATE_RetVal(/** return type */ bool, FGammaDelegate)
DECLARE_DELEGATE_RetVal_OneParam(bool, FDeltaDelegate, bool)
// _TwoParams, _ThreeParams, _FourParams, _FiveParams, _SixParams, _SevenParams, _EightParams, _NineParams

// UDELEGATE( /** UFUNCTION Specifiers */ )
// DECLARE_DELEGATE(FEpsiloneDelegate)

/**
 * # Dynamic Delegate
 * - Reflection 
 * - BindUFunction is only option
 * - Specifiers
 *   - BlueprintReadWrite
 *     - Use "Set ***" to assign delegate instance to a custom event, etc.
 *     - Use "Get ***" and assign it to other delegates like a callback
 *   - EditAnywhere had no effect, it stayed read only in Class Defaults
 *   - VisibleAnywhere didn't negate BlueprintReadWrite, but allows it to be visible in Class Defaults
 *   x BlueprintCallable ( multicast delegates only )
 *   x BlueprintAssignable ( multicast delegates only )
 */
DECLARE_DYNAMIC_DELEGATE(FAlphaDynamicDelegate);
// _OneParam, _TwoParams, ..., _NineParams
// _RetVal, _RetVal_OneParam, _RetVal_TwoParams, ..., _RetVal_NineParams

/**
 * # Dynamic Multicast Delegate
 * - Instead of Bind, there is Add/AddUnique
 * - Instead of Execute, there is Broadcast()
 * - There is no "Broadcast" method in blueprint, use BlueprintCallable and "Call MyMulticastDelegateName" to broadcast.
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAlphaDynamicMulticastDelegate);
// _OneParam, _TwoParams, ..., _NineParams

// DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE(/** Sparse Delegate Class */, /** OwningClass */, FAlphaDynamicMulticastSparseDelegate)
// _OneParam, _TwoParams, ..., _NineParams

namespace AlphaNamespace
{
	DECLARE_DELEGATE(FZetaDelegate)
}

/**
 * Contains different permutations of delegates
 */
UCLASS()
class LEARNINGUE4_API ADelegateActor : public AActor
{
	GENERATED_BODY()

public:
	DECLARE_DELEGATE(FEtaDelegate)

	// Blueprint:
	// - Type: Delegate
	// - Value = Default__DelegateActor.AlphaDynamicCallback
	// C++ UFUNCTION AlphaDynamicCallback is bound to this
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "LearningUE4 | Delegates")
	FAlphaDynamicDelegate AlphaDynamicDelegate;

	// In blueprint this is assigned to AlphaDynamicDelegate
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "LearningUE4 | Delegates")
	FAlphaDynamicDelegate BetaDynamicDelegate;

	// C++ UFUNCTION AlphaDynamicMulticastCallback is bound to this in the constructor
	// a custom blueprint event is bound to this
	UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, Category = "LearningUE4 | Delegates")
	FAlphaDynamicMulticastDelegate AlphaDynamicMulticastDelegate;

private:
	// See constructor for bindings
	FAlphaDelegate AlphaDelegate_Lambda;
	FAlphaDelegate AlphaDelegate_Raw;
	FAlphaDelegate AlphaDelegate_SP;
	FAlphaDelegate AlphaDelegate_Static;
	FAlphaDelegate AlphaDelegate_ThreadSafeSP;
	FAlphaDelegate AlphaDelegate_UFunction;
	FAlphaDelegate AlphaDelegate_UObject;

	AlphaNamespace::FZetaDelegate ZetaDelegate;

	FEtaDelegate EtaDelegate;

public:	
	// Sets default values for this actor's properties
	ADelegateActor();
	~ADelegateActor();

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	void AlphaRawCallback()
	{
		UE_LOG(LogTemp, Warning, TEXT("ADelegateActor::AlphaRawCallback()"));
	}

	void AlphaUObjectCallback()
	{
		UE_LOG(LogTemp, Warning, TEXT("ADelegateActor::AlphaUObjectCallback()"));
	}

	UFUNCTION()
	void AlphaUFunctionCallback()
	{
		UE_LOG(LogTemp, Warning, TEXT("ADelegateActor::AlphaUFunctionCallback()"));
	}

	static void AlphaStaticCallback()
	{
		UE_LOG(LogTemp, Warning, TEXT("ADelegateActor::AlphaStaticCallback()"));
	}

	UFUNCTION()
	void AlphaDynamicCallback()
	{
		UE_LOG(LogTemp, Warning, TEXT("ADelegateActor::AlphaDynamicCallback()"));
	}

	UFUNCTION()
	void AlphaDynamicMulticastCallback()
	{
		UE_LOG(LogTemp, Warning, TEXT("ADelegateActor::AlphaDynamicMulticastCallback()"));
	}
};
