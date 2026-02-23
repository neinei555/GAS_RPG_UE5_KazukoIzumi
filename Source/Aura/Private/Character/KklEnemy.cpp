// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/KklEnemy.h"
#include "AbilitySystem/KklAbilitySystemComponent.h"
#include "AbilitySystem/KklAttributeSet.h"
#include "Aura/Aura.h"


AKklEnemy::AKklEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility,ECR_Block);
    
	AbilitySystemComponent = CreateDefaultSubobject<UKklAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	AttributeSet = CreateDefaultSubobject<UKklAttributeSet>(TEXT("AttributeSet"));
}
void AKklEnemy::BeginPlay()
{
	Super::BeginPlay();
	InitAbilityActorInfo();
}

void AKklEnemy::InitAbilityActorInfo()
{
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	Cast<UKklAbilitySystemComponent>(AbilitySystemComponent)->AbilityActorInfoSet();
}

void AKklEnemy::HiglightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);

	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}

void AKklEnemy::UnHiglightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);

}

int32 AKklEnemy::GetPlayerLevel()
{
	return Level;
}
