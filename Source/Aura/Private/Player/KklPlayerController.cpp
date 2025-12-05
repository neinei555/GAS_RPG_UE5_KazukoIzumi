// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/KklPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"


AKklPlayerController::AKklPlayerController()
{
	bReplicates = true;
}

void AKklPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(KklInputMappingContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(KklInputMappingContext, 0);
    
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);

}

void AKklPlayerController::SetupInputComponent()
{
    APlayerController::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AKklPlayerController::Move);
}

void AKklPlayerController::Move(const FInputActionValue& Value)
{
	const FVector2D InputActionVector = Value.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

    if(APawn* ControllerPawn = GetPawn<APawn>())
	{
		ControllerPawn->AddMovementInput(ForwardDirection, InputActionVector.Y);
		ControllerPawn->AddMovementInput(RightDirection, InputActionVector.X);
	}
}
