// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Data/Attributeinfo.h"
#include "UI/WidegetController/KklWidgetController.h"
#include "AttributeMenuWidgetController.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAttributeInfoSignature, const FKklAttributeInfo,Info);

UCLASS(Blueprintable, BlueprintType)
class AURA_API UAttributeMenuWidgetController : public UKklWidgetController
{
	GENERATED_BODY()

public:
	virtual void BindCallbacksToDependencies() override;

	virtual void BroadcastInitialValues() override;
	
	UPROPERTY(BlueprintAssignable,Category="GAS|Attributes")
	FAttributeInfoSignature AttributeInfoDelegate;
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UAttributeinfo> AttributeInfo;
	
private:
	void BroadcastAttributeInfo(const FGameplayTag& AttributeTag,const FGameplayAttribute& Attribute) const;
};
