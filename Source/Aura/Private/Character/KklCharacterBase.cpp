

#include "Character/KklCharacterBase.h"

AKklCharacterBase::AKklCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Weapon"));
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AKklCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}


