// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/KklCharacter.h"

#include "AbilitySystem/KklAbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
AKklCharacter::AKklCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
}

void AKklCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	// Init Ability Actor Info for the server
	InitAbilityActorInfo();
	AddCharacterAbilities();
}

void AKklCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	// Init Ability Actor Info for the client
	InitAbilityActorInfo();
}

int32 AKklCharacter::GetPlayerLevel()
{
	AKklPlayerState* KklPlayerState = GetPlayerState<AKklPlayerState>();
	return KklPlayerState->GetPlayerLevel();
}

void AKklCharacter::InitAbilityActorInfo()
{
	AKklPlayerState* KklPlayerState = GetPlayerState<AKklPlayerState>();
	check(KklPlayerState);
	KklPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(KklPlayerState, this);
	Cast<UKklAbilitySystemComponent>(KklPlayerState->GetAbilitySystemComponent())->AbilityActorInfoSet();
	AbilitySystemComponent = KklPlayerState->GetAbilitySystemComponent();
	AttributeSet = KklPlayerState->GetAttributeSet();

	if (AKklPlayerController* KklPC = Cast<AKklPlayerController>(GetController()))
	{
		if (AKklHUD* KklHUD = Cast<AKklHUD>(KklPC->GetHUD()))
		{
			KklHUD->InitOverlay(KklPC, KklPlayerState, AbilitySystemComponent, AttributeSet);
		}
	}
    InitializeDefaultAttributes();
}
