// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidegetController/AttributeMenuWidgetController.h"

#include "KklGameplayTags.h"
#include "AbilitySystem/KklAttributeSet.h"

void UAttributeMenuWidgetController::BindCallbacksToDependencies()
{
	Super::BindCallbacksToDependencies();
}

void UAttributeMenuWidgetController::BroadcastInitialValues()
{
	UKklAttributeSet* AS=CastChecked<UKklAttributeSet>(AttributeSet);
	
	FKklAttributeInfo Info=AttributeInfo->FindAttributeInfoForTag(FKklGameplayTags::Get().Attributes_Primary_Strength);
	Info.AttributeValue=AS->GetStrength();
	AttributeInfoDelegate.Broadcast(Info);
	for (auto i :FKklGameplayTags::Get())
}
