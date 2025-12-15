// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "KklUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UKklUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* NewWidgetController);

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> widgetcontroller;;
protected:
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
};
