// Fill out your copyright notice in the Description page of Project Settings.


#include "KklCharacterBase.h"

// Sets default values
AKklCharacterBase::AKklCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AKklCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AKklCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AKklCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

