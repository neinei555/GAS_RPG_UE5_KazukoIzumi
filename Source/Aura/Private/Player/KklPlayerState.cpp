// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/KklPlayerState.h"
#include "AbilitySystem/KklAbilitySystemComponent.h"
#include "AbilitySystem/KklAttributeSet.h"
#include "Net/UnrealNetwork.h"

AKklPlayerState::AKklPlayerState()
{
	NetUpdateFrequency = 100.f;

	AbilitySystemComponent = CreateDefaultSubobject<UKklAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UKklAttributeSet>(TEXT("AttributeSet"));
}

void AKklPlayerState::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME(AKklPlayerState,Level);
}

UAbilitySystemComponent* AKklPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AKklPlayerState::OnRep_Level(int32 OldLevel)
{
}

