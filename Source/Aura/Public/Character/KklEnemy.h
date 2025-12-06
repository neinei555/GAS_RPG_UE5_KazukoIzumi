// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/KklCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "KklEnemy.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AKklEnemy : public AKklCharacterBase,public IEnemyInterface
{
	GENERATED_BODY()

public:
	AKklEnemy();

	virtual void HiglightActor() override;
	virtual void UnHiglightActor() override;
	
};
