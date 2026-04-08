

#include "Player/KklPlayerController.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "KklGameplayTags.h"
#include "NavigationPath.h"
#include "NavigationSystem.h"
#include "Input/KKlEnhancedInputComponent.h"


AKklPlayerController::AKklPlayerController()
{
	bReplicates = true;
	Spline=CreateDefaultSubobject<USplineComponent>("Spline");
}

void AKklPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	CurserTrace();
	
	AutoRun();
}

void AKklPlayerController::AutoRun()
{
	if (!bAutoRunning) return;
	if (APawn* ControllerPawn = GetPawn())
	{
		const FVector LocationOnSpline=Spline->FindLocationClosestToWorldLocation(ControllerPawn->GetActorLocation(),ESplineCoordinateSpace::World);
		const FVector Direction=Spline->FindDirectionClosestToWorldLocation(LocationOnSpline,ESplineCoordinateSpace::World);;
		ControllerPawn->AddMovementInput(Direction);
		
		const float DistanceToDestination=(LocationOnSpline-CachedDestination).Length();
		if (DistanceToDestination<=AutoRunAcceptanceRadius)
		{
			bAutoRunning=false;
		}
	}
}

void AKklPlayerController::CurserTrace()
{
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	if (!CursorHit.bBlockingHit) return;
	LastActor = ThisActor;
	ThisActor = Cast<IEnemyInterface>(CursorHit.GetActor());

	if (LastActor!=ThisActor)
	{
		if (LastActor) LastActor->UnHiglightActor();
		if (ThisActor) ThisActor->HiglightActor();
	}
}

void AKklPlayerController::AbilityInputTagPressed(FGameplayTag InputTag)
{
	if (InputTag.MatchesTagExact(FKklGameplayTags::Get().InputTag_LMB))
	{
		bTargeting=ThisActor?true:false;
		bAutoRunning=false;
	}
}

void AKklPlayerController::AbilityInputTagReleased(FGameplayTag InputTag)
{
	if (!InputTag.MatchesTagExact(FKklGameplayTags::Get().InputTag_LMB) || bTargeting)
	{
		if (GetASC())
		{
			GetASC()->AbilityInputTagReleased(InputTag);
		}
		return ;
	}
	
	APawn* ControllPawn=GetPawn();
	if (FollowTime<=ShortPressThreshold && ControllPawn)
	{
		UNavigationPath* NavPath=UNavigationSystemV1::FindPathToLocationSynchronously(this,ControllPawn->GetActorLocation(),CachedDestination);
		if (NavPath)
		{
			Spline->ClearSplinePoints();
			for (const FVector& PointLoc:NavPath->PathPoints)
			{
				Spline->AddSplinePoint(PointLoc,ESplineCoordinateSpace::World);
			}
			CachedDestination=NavPath->PathPoints[NavPath->PathPoints.Num()-1];
			bAutoRunning=true;
		}
	}
	FollowTime=0.f;
	bTargeting=false;
}

void AKklPlayerController::AbilityInputTagHeld(FGameplayTag InputTag)
{
	if (!InputTag.MatchesTagExact(FKklGameplayTags::Get().InputTag_LMB) || bTargeting)
	{
		if (GetASC())
		{
			GetASC()->AbilityInputTagHeld(InputTag);
		}
		return ;
	}
		FollowTime+=GetWorld()->GetDeltaSeconds();
		if (CursorHit.bBlockingHit)
		{
			CachedDestination=CursorHit.ImpactPoint;
		}
		if (APawn* ControllerPawn = GetPawn())
		{
			const FVector WorldDirection=(CachedDestination-ControllerPawn->GetActorLocation()).GetSafeNormal();
			ControllerPawn->AddMovementInput(WorldDirection);
		}
	

}

UKklAbilitySystemComponent* AKklPlayerController::GetASC()
{
	if (KklAbilitySystemComponent == nullptr)
	{
		KklAbilitySystemComponent=Cast<UKklAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetPawn<APawn>()));
	}
	return KklAbilitySystemComponent;
}


void AKklPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(KklInputMappingContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem != nullptr)
	{
		Subsystem->AddMappingContext(KklInputMappingContext, 0);
	}

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

	UKKlEnhancedInputComponent* KKlEnhancedInputComponent = CastChecked<UKKlEnhancedInputComponent>(InputComponent);

	KKlEnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AKklPlayerController::Move);
	KKlEnhancedInputComponent->BindAbilityAction(InputConfig,this,&ThisClass::AbilityInputTagPressed,&ThisClass::AbilityInputTagReleased,&ThisClass::AbilityInputTagHeld);
}

void AKklPlayerController::Move(const FInputActionValue& Value)
{
	const FVector2D InputActionVector = Value.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControllerPawn = GetPawn<APawn>())
	{
		ControllerPawn->AddMovementInput(ForwardDirection, InputActionVector.Y);
		ControllerPawn->AddMovementInput(RightDirection, InputActionVector.X);
	}
}

