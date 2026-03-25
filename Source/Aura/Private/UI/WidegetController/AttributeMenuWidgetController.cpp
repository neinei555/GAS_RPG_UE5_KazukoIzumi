// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidegetController/AttributeMenuWidgetController.h"

#include "KklGameplayTags.h"
#include "AbilitySystem/KklAttributeSet.h"

void UAttributeMenuWidgetController::BindCallbacksToDependencies()
{
	UKklAttributeSet* AS=CastChecked<UKklAttributeSet>(AttributeSet);
	for (auto& Pair:AS->TagsToAttributes)
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Pair.Value()).AddLambda(
			[this,Pair,AS](const FOnAttributeChangeData& Data)
			{
				BroadcastAttributeInfo(Pair.Key,Pair.Value());		
			}
			);
	}
}

void UAttributeMenuWidgetController::BroadcastInitialValues()
{
	UKklAttributeSet* AS=CastChecked<UKklAttributeSet>(AttributeSet);
	
	for (auto& Pair:AS->TagsToAttributes)
	{
		BroadcastAttributeInfo(Pair.Key,Pair.Value());
	}
	
}

void UAttributeMenuWidgetController::BroadcastAttributeInfo(const FGameplayTag& AttributeTag,const FGameplayAttribute& Attribute) const
{
	FKklAttributeInfo Info=AttributeInfo->FindAttributeInfoForTag(AttributeTag);
	Info.AttributeValue=Attribute.GetNumericValue(AttributeSet);
	AttributeInfoDelegate.Broadcast(Info);
}
