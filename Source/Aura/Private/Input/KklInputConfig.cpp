// Fill out your copyright notice in the Description page of Project Settings.


#include "Input/KklInputConfig.h"

const UInputAction* UKklInputConfig::FindAbilityInputActionForTag(const FGameplayTag& InputTag, bool bLogNotFind) const
{
	for (const FKklInputAction& Action : AbilityInputActions)
	{
		if (Action.InputAction && Action.InputTag == InputTag)
		{
			return Action.InputAction;
		}
	}

	return nullptr;	
}
