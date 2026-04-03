#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/KklAbilitySystemComponent.h"
#include "Components/SplineComponent.h"
#include "GameFramework/PlayerController.h"
#include "Input/KklInputConfig.h"
#include "Interaction/EnemyInterface.h"
#include "KklPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
/**
 *
 */
UCLASS()
class AURA_API AKklPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AKklPlayerController();
	virtual void PlayerTick(float DeltaTime) override;

	IEnemyInterface* ThisActor;
	IEnemyInterface* LastActor;
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
private:
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> KklInputMappingContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	void Move(const FInputActionValue& Value);

	void CurserTrace();
    
	void AbilityInputTagPressed(FGameplayTag InputTag);
	void AbilityInputTagReleased(FGameplayTag InputTag);
	void AbilityInputTagHeld(FGameplayTag InputTag);
	
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UKklInputConfig> InputConfig ;
	
	UPROPERTY()
	TObjectPtr<UKklAbilitySystemComponent> KklAbilitySystemComponent;
	
	UKklAbilitySystemComponent* GetASC();
	
	FVector CachedDestination=FVector::ZeroVector;
	float FollowTime=0.f;
	float ShortPressThreshold=0.5f;
	bool bAutoRunning=false;
	bool bTargeting=false;
	
	UPROPERTY(EditDefaultsOnly)
	float AutoRunAcceptanceRadius=50.f;
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USplineComponent> Spline;
	
	void AutoRun();
};