
#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "LearnSQLiteCoreBPLibrary.generated.h"

UCLASS()
class ULearnSQLiteCoreBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintCallable, Category="LearnSQLiteCore")
	static void Alpha();
};
