// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "KklAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UKklAssetManager : public UAssetManager
{
	GENERATED_BODY()
public:
	static UKklAssetManager& Get();
	
protected:
	virtual void StartInitialLoading() override;
};
