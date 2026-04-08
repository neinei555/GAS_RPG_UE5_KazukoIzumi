// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/KklProjectile.h"

AKklProjectile::AKklProjectile()
{
	PrimaryActorTick.bCanEverTick = true;
    bReplicates = true;
	
	Sphere=CreateDefaultSubobject<USphereComponent>("Sphere");
	SetRootComponent(Sphere);
	Sphere->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	Sphere->SetCollisionResponseToAllChannels(ECR_Ignore);
	Sphere->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Overlap);
	Sphere->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Overlap);
	Sphere->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	
	ProjectileMovementComponent=CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovementComponent");
	ProjectileMovementComponent->InitialSpeed=550.f;
	ProjectileMovementComponent->MaxSpeed=550.f;
	ProjectileMovementComponent->ProjectileGravityScale=0.f;
}

void AKklProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

void AKklProjectile::OnSphereOverlay(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}


