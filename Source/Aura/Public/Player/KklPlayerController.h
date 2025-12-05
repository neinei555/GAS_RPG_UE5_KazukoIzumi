
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
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
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
private:
	UPROPERTY(EditAnywhere, Category ="Input")
	TObjectPtr<UInputMappingContext> KklInputMappingContext;
	
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	void Move(const FInputActionValue& Value);
};
