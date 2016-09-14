// Fill out your copyright notice in the Description page of Project Settings.

#include "coopgame.h"
#include <GameFramework/InputSettings.h>
#include "UInputRemappingFunctionLibrary.h"

bool UUInputRemappingFunctionLibrary::RebindInputAction()
{
	// get the default input settings
	auto inputSettings = const_cast<UInputSettings*>(GetDefault<UInputSettings>());
	if (!inputSettings)
		return false;

	// get the action mappings
	auto& actions = inputSettings->ActionMappings;

	// find the one we're looking for
	for (auto& inputActionKeyMapping : actions)
	{
		if (inputActionKeyMapping.ActionName == inputActionKeyMapping.ActionName)
		{

		}
	}

	return false;
}
