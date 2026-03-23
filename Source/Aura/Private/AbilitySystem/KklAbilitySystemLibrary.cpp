// Fill out your copyright notice in the Descriptio#include "AbilitySystem/KklOverlayWidgetController.h"
#include "AbilitySystem/KklAbilitySystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Player/KklPlayerState.h"
#include "UI/HUD/KklHUD.h"

UOverlayWidgetController* UKklAbilitySystemLibrary::GetOverlayWidgetController(const UObject* WorldContextObject)
{
	if (APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if (AKklHUD* KklHUD= Cast<AKklHUD>(PC->GetHUD()))
		{
			AKklPlayerState* PS = PC->GetPlayerState<AKklPlayerState>();
			UAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();
			UAttributeSet* AS = PS->GetAttributeSet();
			const FWidgetControllerParams WidgetControllerParams(PC, PS,ASC, AS);
			return KklHUD->GetOverlayWidgetController(WidgetControllerParams);
		}
	}
	return nullptr;
}

UAttributeMenuWidgetController* UKklAbilitySystemLibrary::GetAttributeMenuWidgetController(
	const UObject* WorldContextObject)
{
	if (APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if (AKklHUD* KklHUD= Cast<AKklHUD>(PC->GetHUD()))
		{
			AKklPlayerState* PS = PC->GetPlayerState<AKklPlayerState>();
			UAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();
			UAttributeSet* AS = PS->GetAttributeSet();
			const FWidgetControllerParams WidgetControllerParams(PC, PS,ASC, AS);
			return KklHUD->GetAttributeMenuWidgetController(WidgetControllerParams);
		}
	}
	return nullptr;
}


