// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/WidegetController/KklWidgetController.h"
#include "AbilitySystem/KklAttributeSet.h"
#include "AttributeSet.h"
#include "GameplayEffectTypes.h"
#include "UI/Widget/KklUserWidget.h"
#include "OverlayWidgetController.generated.h"

struct FOnAttributeChangeData;
USTRUCT(Blueprintable)
struct  FUIWidgetRow: public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	FGameplayTag MessageTag=FGameplayTag();

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	FText Message=FText();
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	TSubclassOf<UKklUserWidget> WidgetClass= nullptr;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	UTexture2D* Image= nullptr;
};
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttributeChangedSignature, float, NewValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMessageWidegetRowSignature, FUIWidgetRow, Row);
/**
 * 
 */
UCLASS(BlueprintType,Blueprintable)
class AURA_API UOverlayWidgetController : public UKklWidgetController
{
	GENERATED_BODY()
public:
	virtual void BroadcastInitialValues() override;
	virtual void BindCallbacksToDependencies() override;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnAttributeChangedSignature OnHealthChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnAttributeChangedSignature OnMaxHealthChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnAttributeChangedSignature OnManaChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnAttributeChangedSignature OnMaxManaChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Message")
    FMessageWidegetRowSignature MessageWidgetRowDelegate;
protected:

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Widget Data")
	TObjectPtr<UDataTable> MessageTable;

	template<typename T>
	T* GetDataTableRowByTag(const UDataTable* DataTable,const FGameplayTag& RowTag) const;
};

template <typename T>
T* UOverlayWidgetController::GetDataTableRowByTag(const UDataTable* DataTable, const FGameplayTag& RowTag) const
{
    return DataTable->FindRow<T>(RowTag.GetTagName(),TEXT(""));	
}
