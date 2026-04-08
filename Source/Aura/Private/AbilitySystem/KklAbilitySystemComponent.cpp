// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/KklAbilitySystemComponent.h"

#include <ThirdParty/ShaderConductor/ShaderConductor/External/DirectXShaderCompiler/include/dxc/DXIL/DxilConstants.h>

#include "AbilitySystem/Abilites/KklGameplayAbility.h"

void UKklAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UKklAbilitySystemComponent::ClientEffectApplied);
}

void UKklAbilitySystemComponent::AddCharacterAbilities(const TArray<TSubclassOf<UGameplayAbility>>& StartupAbilities)
{
	for ( auto& StartupAbility : StartupAbilities)
	{
		FGameplayAbilitySpec AbilitySpec= FGameplayAbilitySpec(StartupAbility,1);
		if (const UKklGameplayAbility* KklAbility=Cast<UKklGameplayAbility>(AbilitySpec.Ability))
		{
		    AbilitySpec.DynamicAbilityTags.AddTag(KklAbility->StartupInputTag);
			GiveAbility(AbilitySpec);
		}
	}
}

void UKklAbilitySystemComponent::AbilityInputTagHeld(const FGameplayTag& InputTag)
{
	if (!InputTag.IsValid())return;
	for (FGameplayAbilitySpec& AbilitySpec: GetActivatableAbilities())
	{
		if (AbilitySpec.DynamicAbilityTags.HasTag(InputTag))
		{
			AbilitySpecInputPressed(AbilitySpec);
			if (!AbilitySpec.IsActive())
			{
				TryActivateAbility(AbilitySpec.Handle);
			}
		}
	}
}

void UKklAbilitySystemComponent::AbilityInputTagReleased(const FGameplayTag& InputTag)
{
	if (!InputTag.IsValid())return;
	for (FGameplayAbilitySpec& AbilitySpec: GetActivatableAbilities())
	{
		if (AbilitySpec.DynamicAbilityTags.HasTag(InputTag))
		{
			AbilitySpecInputReleased(AbilitySpec);
		}
	}
}

void UKklAbilitySystemComponent::ClientEffectApplied_Implementation(UAbilitySystemComponent* AbilitySystemComponent,
                                               const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer);

	EffectAssetTags.Broadcast(TagContainer);
	
	
	
}
