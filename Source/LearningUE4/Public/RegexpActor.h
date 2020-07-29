// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include <Internationalization/Regex.h>
// FRegexPattern, FRegexMatcher

#include "RegexpActor.generated.h"

/**
 * 
 */
UCLASS()
class LEARNINGUE4_API ARegexpActor : public AActor
{
	GENERATED_BODY()
	
public:
	// The string to parse
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LearningUE4|Regex")
	FString InputString;

	// The regex to use on InputString
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LearningUE4|Regex")
	FString RegexPatternString;

public:	
	// Sets default values for this actor's properties
	ARegexpActor();

	// ## UOBject Interface 
	virtual void PostInitProperties() override;

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
	// ## ~UOBject Interface

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	void UpdateDependentVariables();
};
