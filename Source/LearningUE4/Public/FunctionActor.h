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
	// C++ Only
	// - Not exposed to blueprints
	void Alpha() 
	{
	}

	// Empty UFUNCTION
	// - Not exposed to blueprint
	// - todo
	UFUNCTION()
	void Beta() 
	{
	}

	// No compiler error, but not exposed to blueprints
	// UFUNCTION(Category = Default)
	// void Gamma() 
	// {
	// }

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

	// Function Return Value
	// Has a boolean return value titled "Return Value"
	UFUNCTION(BlueprintCallable, Category = "LearningUE4 | Functions")
	bool Zeta() 
	{
		return true;
	}

	// Out Return Value
	// Has a boolean return value titled "Arg"
	UFUNCTION(BlueprintCallable, Category = "LearningUE4 | Functions")
	void Eta(/** OUT */ bool& bArg)
	{
		bArg = true;
	}

	// Parameter Custom Display Name
	// - Has return value titled "Output Argument"
	// REFERENCE: https://answers.unrealengine.com/questions/527068/view.html
	UFUNCTION(BlueprintCallable, Category = "LearningUE4 | Functions")
	void Theta( UPARAM(DisplayName="Ouput Argument") bool& bArg ) 
	{
	}

	// Blueprint Pure
	// - No 'Exec' pins
	// - Has return value titled 'Return value'
	// - has no input like the next example, Kappa
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "LearningUE4 | Functions")
	bool Iota()
	{
		return true;
	}

	// Blueprint Pure via const Keyword
	// - has input 'Target' that defaults to 'self'
	// https://www.tomlooman.com/ue4-ufunction-keywords-explained/
	UFUNCTION(BlueprintCallable, Category = "LearningUE4 | Functions")
	bool Kappa() const
	{
		return true;
	}

	// Lambda
	// Mu
	// Nu
	// Xi
	// Omicron
	// Pi
	// Rho
	// Sigma
	// Tau
	// Upsilon
	// Phi
	// Chi
	// Psi
	// Omega
};
