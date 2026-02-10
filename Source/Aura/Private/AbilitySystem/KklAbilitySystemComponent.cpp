// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/KklAbilitySystemComponent.h"

void UKklAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UKklAbilitySystemComponent::EffectApplied);
}

void UKklAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent,
                                               const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("EffectApplied"));
}
