// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "Attributeinfo.generated.h"


USTRUCT(BlueprintType)
struct FKklAttributeInfo
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FGameplayTag AttributeTag=FGameplayTag();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText AttributeName=FText();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText AttributeDescription=FText();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float AttributeValue=0.0f;
	
};
/**
 * 
 */
UCLASS()
class AURA_API UAttributeinfo : public UDataAsset
{
	GENERATED_BODY()
public:
	FKklAttributeInfo FindAttributeInfoForTag(const FGameplayTag& AttributeTag,bool bLogNotFound=false) const;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	TArray<FKklAttributeInfo> AttributeInformation;
};
