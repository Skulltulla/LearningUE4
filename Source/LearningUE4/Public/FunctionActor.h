// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FunctionActor.generated.h"

/**
 * Contains different permutations of UFUNCTION
 */
UCLASS()
class LEARNINGUE4_API AFunctionActor : public AActor
{
	GENERATED_BODY()

public:
	bool bAlpha = false;
	
public:	
	// Sets default values for this actor's properties
	AFunctionActor();
	~AFunctionActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	// No reflection macro
	// - Not exposed to blueprints
	void Alpha() 
	{
	}

	// Empty UFUNCTION
	// - Not exposed to blueprint
	// - todo
	// - Some delegates require the callback method to be a UFUNCTION (See MediaPlayer.OnOpened...
	UFUNCTION()
	void Beta() 
	{
	}

	// No compiler error like UPROPERTY, but not exposed to blueprints
	UFUNCTION(Category = "LearningUE4 | Functions")
	void Gamma() 
	{
	}

	// Blueprint Callable
	// - Exposed to blueprints
	// - Has untitled 'Exec' pins (e.g. similar to 'execute' and 'then' in Blueprint Macros)
	UFUNCTION(BlueprintCallable, Category = "LearningUE4 | Functions")
	void Delta() 
	{
	}

	// UFUNCTION meta
	// - Exposed to blueprint as DisplayName
	// - Keywords can be used when searching in the blueprint graph
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Calculate Epsilon", Keywords = "LearningUE4 functions meta metadata"), Category = "LearningUE4 | Functions")
	void Epsilon() 
	{
	}

	// Return Value
	// - Has a boolean return value titled "Return Value"
	UFUNCTION(BlueprintCallable, Category = "LearningUE4 | Functions")
	bool Zeta() 
	{
		return true;
	}

	// Out Param
	// - Has a boolean return value titled "Arg"
	UFUNCTION(BlueprintCallable, Category = "LearningUE4 | Functions")
	void Eta(/** OUT */ bool& bArg)
	{
		bArg = true;
	}
	
	// ref parameter
	// - appears on input side of a blueprint node
	// - UObjects and AActors must use * instead of &
	UFUNCTION(BlueprintCallable, Category = "LearningUE4 | Functions")
	void Eta2( UPARAM(ref) bool& bArg )
	{
	}
	
	// Invalid attempt of pass by reference
	// Compiler Error: "cannot have exposed pointer to this type"
	// UFUNCTION(BlueprintCallable, Category = "LearningUE4 | Functions")
	// void Eta3(bool* bArg){}

	// Parameter Custom Display Name
	// - Has return value with title of DisplayName
	// REFERENCE: https://answers.unrealengine.com/questions/527068/view.html
	UFUNCTION(BlueprintCallable, Category = "LearningUE4 | Functions")
	void Theta( UPARAM(DisplayName="Ouput Argument") bool& bArg ) 
	{
	}

	// Blueprint Pure 1/3
	// Blueprint Pure without const keyword
	// - No 'Exec' pins
	// - has no input pin without const keyword (see next examples)
	// - bad convention; no compiler error if member is modified
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "LearningUE4 | Functions")
	void Iota(bool& bOut)
	{
		bAlpha = !bAlpha; // side effect, but no compiler error
		bOut = bAlpha;
	}

	// Blueprint Pure 2/3
	// Blueprint Pure with const keyword
	// - has input 'Target' that defaults to 'self' (similar to Kappa)
	// - throws compile error if a member is modified
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "LearningUE4 | Functions")
	void Iota2(bool& bOut) const
	{
		// bAlpha = !bAlpha; // compiler error C3490
		bOut = bAlpha;
	}

	// Blueprint Pure 3/3
	// Blueprint Pure via const keyword, but without specifier
	// - has input 'Target' that defaults to 'self'
	// - throws compile error if a member is modified
	// REFERENCE: https://www.tomlooman.com/ue4-ufunction-keywords-explained/
	UFUNCTION(BlueprintCallable, Category = "LearningUE4 | Functions")
	bool Kappa() const
	{
		// bAlpha = !bAlpha // compiler error C3490
		return bAlpha;
	}

	// Blueprint Implementable Event (no return value or out param)
	// - May optionally be implemented in blueprints 
	// - May be invoked from C++ (no native definition required)
	// - "Event Lambda" is node title
	// - Not callable from blueprint without `BlueprintCallable` specifier
	UFUNCTION(BlueprintImplementableEvent, Category = "LearningUE4 | Functions ")
	void Lambda();

	// Blueprint Implementable Event (with input)
	UFUNCTION(BlueprintImplementableEvent, Category = "LearningUE4 | Functions ")
	void Lambda2(bool bArg0);

	// Blueprint Implementable Event (with return value)
	// - Not an event - creates an overridable function 
	// - May be invoked from C++ (no native definition required)
	// - Not callable from blueprint without 'BlueprintCallable` specifier
	UFUNCTION(BlueprintImplementableEvent, Category = "LearningUE4 | Functions ")
	bool Mu();

	// Blueprint Implementable Event (with out param)
	// - Similar to previous example, Mu
	// - Not an event - creates an overridable function 
	// - May be invoked from C++ (no native definition required)
	// - Not callable from blueprint without `BlueprintCallable` specifier
	UFUNCTION(BlueprintImplementableEvent, Category = "LearningUE4 | Functions")
	void Nu(bool& bOut);

	// BlueprintNativeEvent
	// - Requires method "TITLE_Implementation" with definition that provides default functionality
	//   if the event is NOT implemented; otherwise compiler errors will be thrown. Do not define Xi().
	// - Either blueprint event xor native "_Implementation" will be invoked
	// - Not callable from blueprint without `BlueprintCallable` specifier
	UFUNCTION(BlueprintNativeEvent, Category = "LearningUE4 | Functions")
	void Xi();
	void Xi_Implementation()
	{
		UE_LOG(LogTemp, Warning, TEXT("AFunctionActor::Xi_Implementation()"));
	}

	// Static Method
	// - Blueprint node does not have an input pin for an AFunctionActor object
	// - "Target is Function Actor" (blueprint node description)
	UFUNCTION(BlueprintCallable, Category = "LearningUE4 | Functions")
	static void Omicron()
	{
		UE_LOG(LogTemp, Warning, TEXT("AFunctionActor::Omicron()"));
	}

	// Static Method, World Context Object
	// - Blueprint node does not have an input pin for an AFunctionActor object
	// - Blueprint node has an input pin for the world context object;  From the level blueprint, a reference to self may be passed.
	UFUNCTION(BlueprintCallable, Category = "LearningUE4 | Functions")
	static void Pi(UObject* WorldContextObject)
	{
		UE_LOG(LogTemp, Warning, TEXT("AFunctionActor::Pi()"));
		UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	}
	
	// Static Method, meta, World Context Object
	// - Blueprint node does not have an input pin for an AFunctionActor object.
	// - Blueprint node does not have an input pin for WorldContextObject.
	// - https://docs.unrealengine.com/en-US/ProgrammingAndScripting/Blueprints/TechnicalGuide/Guidelines/index.html
	// - https://answers.unrealengine.com/questions/468741/how-to-make-a-blueprint-derived-from-a-uobject-cla.html?sort=oldest
	// - https://www.tomlooman.com/ue4-gameplay-framework/
	UFUNCTION(BlueprintCallable, meta=(WorldContext=WorldContextObject), Category = "LearningUE4 | Functions")
	static void Rho(UObject* WorldContextObject)
	{
		UE_LOG(LogTemp, Warning, TEXT("AFunctionActor::Rho()"));
		UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	}
	
	// Sigma
	// Tau
	// Upsilon
	// Phi
	// Chi
	// Psi
	// Omega
};
