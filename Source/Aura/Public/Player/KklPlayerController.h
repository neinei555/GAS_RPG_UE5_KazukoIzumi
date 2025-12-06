#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
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

};