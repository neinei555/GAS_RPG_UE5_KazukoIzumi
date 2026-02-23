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
	/**  Enemy Interface  */
	virtual void HiglightActor() override;
	virtual void UnHiglightActor() override;
	/**  Enemy Interface  */
	
	/**  Combat Interface  */
	virtual int32 GetPlayerLevel() override;
	/**  Combat Interface  */
protected:
	virtual void BeginPlay() override;

	virtual void InitAbilityActorInfo() override;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Character class Defaults")
	int32 Level=1;
};
