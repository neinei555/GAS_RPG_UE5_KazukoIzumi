// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/KklUserWidget.h"

void UKklUserWidget::SetWidgetController(UObject* NewWidgetController)
{
	widgetcontroller = NewWidgetController;
	WidgetControllerSet();
}
