

#include "Character/KklCharacterBase.h"

#include "EditorDirectories.h"

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

void AKklCharacterBase::ApplyEffectToSelf(TSubclassOf<UGameplayEffect> Effect, float Level) const
{
	check(IsValid(GetAbilitySystemComponent()));
	check(IsValid(Effect));
	const FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(Effect, Level, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());

}

void AKklCharacterBase::InitializeDefaultAttributes()
{
	ApplyEffectToSelf(DefaultPrimaryAttributes,1.0);
	ApplyEffectToSelf(DefaultSecondaryAttributes,1.0);
}



