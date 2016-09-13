// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "UInputRemappingFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class COOPGAME_API UUInputRemappingFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "CoopGame|Input Remapping")
	static bool RebindInputAction();

	
	
};
