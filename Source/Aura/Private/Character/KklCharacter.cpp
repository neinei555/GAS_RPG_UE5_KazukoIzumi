// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/KklCharacter.h"
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
}

void AKklCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	// Init Ability Actor Info for the client
	InitAbilityActorInfo();
}

void AKklCharacter::InitAbilityActorInfo()
{
	AKklPlayerState* KklPlayerState = GetPlayerState<AKklPlayerState>();
	check(KklPlayerState);
	KklPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(KklPlayerState, this);
	AbilitySystemComponent = KklPlayerState->GetAbilitySystemComponent();
	AttributeSet = KklPlayerState->GetAttributeSet();
}
