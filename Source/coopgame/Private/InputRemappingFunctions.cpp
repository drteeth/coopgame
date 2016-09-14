// Fill out your copyright notice in the Description page of Project Settings.

#include "coopgame.h"
#include <GameFramework/InputSettings.h>
#include "InputRemappingFunctions.h"

bool UInputRemappingFunctions::RebindActionMapping(FInputActionKeyMapping from, FInputActionKeyMapping to)
{
	// get the default input settings
	auto inputSettings = const_cast<UInputSettings*>(GetDefault<UInputSettings>());
	if (!inputSettings)
		return false;

	// get the action mapping to rebind
	auto actionMappingToRebind = FindActionKeyMapping(inputSettings, from);
	if (!actionMappingToRebind)
		return false;

	// update it
	*actionMappingToRebind = to;

	// save 
	inputSettings->SaveKeyMappings();

	// rebuild inputs
	for (TObjectIterator<UPlayerInput> playerInput; playerInput; ++playerInput)
	{
		playerInput->ForceRebuildingKeyMaps(true);
	}
	
	return true;
}

FInputActionKeyMapping* UInputRemappingFunctions::FindActionKeyMapping(UInputSettings* inputSettings, FInputActionKeyMapping actionKeyMapping)
{
	// get the action mappings
	auto& actions = inputSettings->ActionMappings;

	// search for the one we're looking for
	for (auto& inputActionKeyMapping : actions)
	{
		if (inputActionKeyMapping.ActionName == actionKeyMapping.ActionName && inputActionKeyMapping.Key == actionKeyMapping.Key)
			return &inputActionKeyMapping;
	}

	// didn't find anything, nullptr
	return nullptr;
}
