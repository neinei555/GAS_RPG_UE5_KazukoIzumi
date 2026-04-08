// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilites/KklGameplayAbility.h"
#include "Actor/KklProjectile.h"
#include "KklProjectileSpell.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UKklProjectileSpell : public UKklGameplayAbility
{
	GENERATED_BODY()
protected:
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
    
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	TSubclassOf<AKklProjectile> ProjectileClass;
};
