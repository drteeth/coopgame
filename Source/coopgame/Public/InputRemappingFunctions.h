// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameFramework/PlayerInput.h"
#include "InputRemappingFunctions.generated.h"

class UInputSettings;

/**
 * 
 */
UCLASS()
class COOPGAME_API UInputRemappingFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "CoopGame|Input Remapping")
	static bool RebindActionMapping(FInputActionKeyMapping from, FInputActionKeyMapping to);
	
private:
	// helper to find a key mapping, returns nullptr if it couldn't find a matching one
	static FInputActionKeyMapping* FindActionKeyMapping(UInputSettings* settings, FInputActionKeyMapping actionKeyMapping);	
	
};
