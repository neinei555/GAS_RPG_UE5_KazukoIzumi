// Fill out your copyright notice in the Description page of Project Settings.


#include "KklAssetManager.h"
#include "KklGameplayTags.h"
UKklAssetManager& UKklAssetManager::Get()
{
	check(GEngine)
	UKklAssetManager* KklAssetManager = Cast<UKklAssetManager>(GEngine->AssetManager);
    return *KklAssetManager;
}

void UKklAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();
	FKklGameplayTags::InitializeNativeGameplayTags();
}
