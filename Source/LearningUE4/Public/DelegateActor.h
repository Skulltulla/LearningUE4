/**
# Delegates 
	Reflection: No

	DECLARE_DELEGATE
	DECLARE_DELEGATE_***Param(s)
	DECLARE_DELEGATE_RetVal
	DECLARE_DELEGATE_RetVal_***Param(s)
	// Bind***: Lambda, Raw, SP, Static, ThreadSafeSP, UFunction, or UObject
	// Execute, ExecuteIfBound

	DECLARE_MULTICAST_DELEGATE
	DECLARE_MULTICAST_DELEGATE_***Param(s)
	// Add***: FSingleDelegate, Lambda, Raw, SP, Static, ThreadSafeSP, UFunction, or UObject
	// Broadcast()

# Dynamic Delegates
	Reflection: Yes

	DECLARE_DYNAMIC_DELEGATE
	DECLARE_DYNAMIC_DELEGATE_***Param(s)
	DECLARE_DYNAMIC_DELEGATE_RetVal
	DECLARE_DYNAMIC_DELEGATE_RetVal_***Param(s)
	// BindUFunction (only)
	// Execute, ExecuteIfBound
	// Specifiers
	//	- BlueprintReadWrite
	//	  - Use "Set ***" to assign a custom event, etc
	//	  - Use "Get ***" and assign it to other delegates like a callback
	//	- EditAnywhere had no effect, it stayed read only in Class Defaults
	//	- VisibleAnywhere didn't negate BlueprintReadWrite, but allows it to be visible in Class Defaults
	//	x BlueprintCallable ( multicast delegates only )
	//	x BlueprintAssignable ( multicast delegates only )
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_***Param(s)
	// Add/AddUnique(FScriptDelegate) (only); NOTE: FScriptDelegate may only be bound to a UFunction
	// Broadcast(); NOTE: There is no "Broadcast" method in blueprint, use BlueprintCallable and "Call MyMulticastDelegateName" to broadcast.

 # Events:
	DECLARE_EVENT
	DECLARE_EVENT_***Param(s)
 */
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DelegateActor.generated.h"

DECLARE_DELEGATE(/** typename */ FAlphaDelegate)
DECLARE_DELEGATE_OneParam(FBetaDelegate, /** param type */ bool)
// _TwoParams, _ThreeParams, _FourParams, _FiveParams, _SixParams, _SevenParams, _EightParams, _NineParams

DECLARE_DELEGATE_RetVal(/** return type */ bool, FGammaDelegate)
DECLARE_DELEGATE_RetVal_OneParam(bool, FDeltaDelegate, bool)
// _TwoParams, _ThreeParams, _FourParams, _FiveParams, _SixParams, _SevenParams, _EightParams, _NineParams

DECLARE_MULTICAST_DELEGATE(FAlphaMulticastDelegate)
DECLARE_MULTICAST_DELEGATE_OneParam(FBetaMulticastDelegate, bool)
// _TwoParams, _ThreeParams, _FourParams, _FiveParams, _SixParams, _SevenParams, _EightParams, _NineParams

// TODO
// UDELEGATE( /** UFUNCTION Specifiers */ )
// DECLARE_DELEGATE_DYNAMIC_***(...)

DECLARE_DYNAMIC_DELEGATE(FAlphaDynamicDelegate);
// _OneParam, _TwoParams, ..., _NineParams
// _RetVal, _RetVal_OneParam, _RetVal_TwoParams, ..., _RetVal_NineParams

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAlphaDynamicMulticastDelegate);
// _OneParam, _TwoParams, ..., _NineParams

// TODO
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

	// todo
	FAlphaMulticastDelegate AlphaMulticastDelegate_Simple;
	FAlphaMulticastDelegate AlphaMulticastDelegate_Lambda;
	FAlphaMulticastDelegate AlphaMulticastDelegate_Raw;
	FAlphaMulticastDelegate AlphaMulticastDelegate_SP;
	FAlphaMulticastDelegate AlphaMulticastDelegate_Static;
	FAlphaMulticastDelegate AlphaMulticastDelegate_ThreadSafeSP;
	FAlphaMulticastDelegate AlphaMulticastDelegate_UFunction;
	FAlphaMulticastDelegate AlphaMulticastDelegate_UObject;

	// The C++ UFUNCTION AlphaDynamicCallback is bound to this in the constructor
	// Blueprint:
	// - Type: Delegate
	// - Value = Default__DelegateActor.AlphaDynamicCallback
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "LearningUE4 | Delegates")
	FAlphaDynamicDelegate AlphaDynamicDelegate;

	// Assigned to `AlphaDynamicDelegate` in Blueprint
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "LearningUE4 | Delegates")
	FAlphaDynamicDelegate BetaDynamicDelegate;

	// The C++ UFUNCTION AlphaDynamicMulticastCallback is bound to this 
	// in the constructor and a custom Blueprint event is also bound to this
	UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, Category = "LearningUE4 | Delegates")
	FAlphaDynamicMulticastDelegate AlphaDynamicMulticastDelegate;

public:	
	ADelegateActor();
	~ADelegateActor();

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

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
