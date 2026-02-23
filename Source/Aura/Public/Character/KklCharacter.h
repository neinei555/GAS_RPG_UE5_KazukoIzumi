// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/KklCharacterBase.h"
#include "Player/KklPlayerState.h"
#include "Player/KklPlayerController.h"
#include "UI/HUD/KklHUD.h"
#include "KklCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AKklCharacter : public AKklCharacterBase
{
	GENERATED_BODY()
public:
	AKklCharacter();
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
	
	/**  Combat Interface  */
	virtual int32 GetPlayerLevel() override;
	/**  Combat Interface  */
private:
	virtual void InitAbilityActorInfo();
};
