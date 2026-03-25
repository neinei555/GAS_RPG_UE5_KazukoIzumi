// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/KklAbilitySystemComponent.h"

void UKklAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UKklAbilitySystemComponent::EffectApplied);
}

void UKklAbilitySystemComponent::AddCharacterAbilities(const TArray<TSubclassOf<UGameplayAbility>>& StartupAbilities)
{
	for ( auto& StartupAbility : StartupAbilities)
	{
		FGameplayAbilitySpec AbilitySpec= FGameplayAbilitySpec(StartupAbility,1);
		GiveAbility(AbilitySpec);
		GiveAbilityAndActivateOnce(AbilitySpec);
	}
}

void UKklAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent,
                                               const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer);

	EffectAssetTags.Broadcast(TagContainer);
	
	
	
}
