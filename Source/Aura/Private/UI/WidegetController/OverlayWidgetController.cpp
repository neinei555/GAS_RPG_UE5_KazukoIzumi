// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidegetController/OverlayWidgetController.h"

#include "AbilitySystem/KklAbilitySystemComponent.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
		UKklAttributeSet* KklAttributeSet = CastChecked<UKklAttributeSet>(AttributeSet);
			OnHealthChanged.Broadcast(KklAttributeSet->GetHealth());
			OnMaxHealthChanged.Broadcast(KklAttributeSet->GetMaxHealth());
			OnManaChanged.Broadcast(KklAttributeSet->GetMana());
			OnMaxManaChanged.Broadcast(KklAttributeSet->GetMaxMana());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	UKklAttributeSet* KklAttributeSet = CastChecked<UKklAttributeSet>(AttributeSet);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		KklAttributeSet->GetHealthAttribute()).AddLambda([this](const FOnAttributeChangeData& Data)
	{
			OnHealthChanged.Broadcast(Data.NewValue);
	});
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		KklAttributeSet->GetMaxHealthAttribute()).AddLambda([this](const FOnAttributeChangeData& Data)
	{
		OnMaxHealthChanged.Broadcast(Data.NewValue);
	});
    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
	   KklAttributeSet->GetManaAttribute()).AddLambda([this](const FOnAttributeChangeData& Data)
	{
		OnManaChanged.Broadcast(Data.NewValue);
	});
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		KklAttributeSet->GetMaxManaAttribute()).AddLambda([this](const FOnAttributeChangeData& Data)
	{
		OnMaxManaChanged.Broadcast(Data.NewValue);
	});

	Cast<UKklAbilitySystemComponent>(AbilitySystemComponent)->EffectAssetTags.AddLambda(
	[this](const FGameplayTagContainer& TagContainer)
	{
		for (const FGameplayTag& Tag : TagContainer)
		{
			FGameplayTag MessageTag=FGameplayTag::RequestGameplayTag(FName("Message"));
           if (Tag.MatchesTag(MessageTag))
			{
           	FUIWidgetRow* Row=GetDataTableRowByTag<FUIWidgetRow>(MessageTable, Tag);
           	MessageWidgetRowDelegate.Broadcast(*Row);
			}
		}
	});
}

