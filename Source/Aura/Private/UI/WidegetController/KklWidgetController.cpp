// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidegetController/KklWidgetController.h"

void UKklWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& Params)
{
	PlayerController = Params.PlayerController;
	PlayerState = Params.PlayerState;
	AbilitySystemComponent = Params.AbilitySystemComponent;
	AttributeSet = Params.AttributeSet;
}

void UKklWidgetController::BroadcastInitialValues()
{
}

void UKklWidgetController::BindCallbacksToDependencies()
{
}
