

#include "Character/KklCharacterBase.h"

AKklCharacterBase::AKklCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Weapon"));
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

UAbilitySystemComponent* AKklCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AKklCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AKklCharacterBase::InitAbilityActorInfo()
{
}

void AKklCharacterBase::InitializePrimaryAttributes() const
{
	const FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
 	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(DefaultPrimaryAttributes, 1.0f, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
}


