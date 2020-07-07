// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VariableActor.generated.h"

/**
 * This comment will appear in the editor when hovering over 
 * the class in the Pick Parent Class dialog.
 */
UCLASS()
class LEARNINGUE4_API AVariableActor : public AActor
{
	GENERATED_BODY()

public:
	// C++ Only 
	// - Not exposed to editor or blueprints
	// - Requires manual memory management for pointers
	bool bAlpha;

	// - Exposed to Unreal Header Tool
	// - Allows the engine to garbage collect it if necessary
	// - Not visible in editor Class Defaults
	// Reference: https://answers.unrealengine.com/questions/507623/what-is-the-difference-between-a-variable-declared.html
	UPROPERTY()
	bool bBeta;

	// Compile Error - has category, but not exposed to editor or blueprints with a specifier
	// UPROPERTY(Category = Default)
	// bool bGamma;

	// Exposed to the editor and blueprints
	// hover over the variable to read this comment
	UPROPERTY(VisibleAnywhere, Category = LearningUE4)
	bool bDelta;

	// An alternative way to create a category
	UPROPERTY(VisibleAnywhere, Category = "LearningUE4")
	bool bEpsilon;

	// Multi-word Category ('Variables' is not subcategory; see bEta)
	UPROPERTY(VisibleAnywhere, Category = "LearningUE4 Variables")
	bool bZeta;

	// Compile Error - Invalid Syntax for multi-word Category
	// UPROPERTY(VisibleAnywhere, Category = LearningUE4 Variables)
	// bool bEta;

	// Subcategories
	// NOTE: If there are further subcategories, they will be in a separate "Variables" category
	UPROPERTY(VisibleAnywhere, Category = "LearningUE4 | Variables")
	bool bEta;

	// An independent variable that bIota depends upon.
	UPROPERTY(EditAnywhere, Category = "LearningUE4 | Variables | Independent")
	bool bTheta = false;

	// A dependent variable which has its value calculated from bTheta
	UPROPERTY(VisibleAnywhere, Category = "LearningUE4 | Variables | Dependent")
	bool bIota;

public:	
	// Sets default values for this actor's properties
	AVariableActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/** UObject interface (See AActor, line ~1613, may change later; NOTE: AActor is a subclass of UObject) */
	virtual void PostInitProperties() override;

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

private:
	// Called from PostInitProperties() and PostEditChangeProperty()
	void UpdateDependentVariables();
};
