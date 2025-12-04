
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "KklCharacterBase.generated.h"

UCLASS(Abstract)
class AURA_API AKklCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	AKklCharacterBase();

protected:

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,Category="Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;
};
