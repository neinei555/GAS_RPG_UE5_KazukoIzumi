

#include "Character/KklCharacterBase.h"

#include "EditorDirectories.h"
#include "AbilitySystem/KklAbilitySystemComponent.h"

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

FVector AKklCharacterBase::GetCombatSocketLocation()
{
	return Weapon->GetSocketLocation(WeaponTipSocketName);
}

void AKklCharacterBase::InitAbilityActorInfo()
{
}

void AKklCharacterBase::ApplyEffectToSelf(TSubclassOf<UGameplayEffect> Effect, float Level) const
{  
	check(IsValid(GetAbilitySystemComponent()));
	check(IsValid(Effect));
	 FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	ContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(Effect, Level, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());

}

void AKklCharacterBase::InitializeDefaultAttributes()
{
	ApplyEffectToSelf(DefaultPrimaryAttributes,1.0);
	ApplyEffectToSelf(DefaultSecondaryAttributes,1.0);
	ApplyEffectToSelf(DefaultVitalAttributes,1.0);
}

void AKklCharacterBase::AddCharacterAbilities()
{
	UKklAbilitySystemComponent* KklASC = Cast<UKklAbilitySystemComponent>(GetAbilitySystemComponent());
	if (!HasAuthority()) return;
	
	KklASC->AddCharacterAbilities(StartupAbilities);
}



