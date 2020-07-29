// Fill out your copyright notice in the Description page of Project Settings.

#include "RegexpActor.h"

DEFINE_LOG_CATEGORY_STATIC(LogRegexpActor, Warning, All);

// Sets default values
ARegexpActor::ARegexpActor()
{
	UE_LOG(LogTemp, Warning, TEXT("ARegexpActor"));
	PrimaryActorTick.bCanEverTick = true;

}

void ARegexpActor::PostInitProperties()
{
	Super::PostInitProperties();
	UpdateDependentVariables();
}

void ARegexpActor::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	UpdateDependentVariables();
	Super::PostEditChangeProperty(PropertyChangedEvent);
}

void ARegexpActor::UpdateDependentVariables()
{
	if (this->RegexPatternString.IsEmpty())
	{
		UE_LOG(LogRegexpActor, Warning, TEXT("UpdateDependentVariables() - Pattern cannot be empty"));
		return;
	}

	const FRegexPattern Pattern(this->RegexPatternString);
	FRegexMatcher Matcher(Pattern, this->InputString);
	int32 index = 0;
	if(Matcher.FindNext())
	{
		FString match = Matcher.GetCaptureGroup(index);
		UE_LOG(LogRegexpActor, Warning, TEXT("Found Match: %s"), *match);
		index++;
	}
	else
	{
		UE_LOG(LogRegexpActor, Warning, TEXT("No matches found (%s, %s)"), *RegexPatternString, *InputString);
	}
}

// Called when the game starts or when spawned
void ARegexpActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ARegexpActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

