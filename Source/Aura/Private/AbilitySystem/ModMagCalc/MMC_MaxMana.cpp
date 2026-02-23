// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/ModMagCalc/MMC_MaxMana.h"

#include "AbilitySystem/KklAttributeSet.h"
#include "Interaction/CombatInterface.h"

UMMC_MaxMana::UMMC_MaxMana()
{
	IntelligenceDef.AttributeToCapture=UKklAttributeSet::GetIntelligenceAttribute();
	IntelligenceDef.AttributeSource=EGameplayEffectAttributeCaptureSource::Target;
	IntelligenceDef.bSnapshot=false;
	
	RelevantAttributesToCapture.Add(UMMC_MaxMana::IntelligenceDef);
}

float UMMC_MaxMana::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	//Gather Tags from source and tafget
	const FGameplayTagContainer* SourceTags=Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags=Spec.CapturedTargetTags.GetAggregatedTags();
	
	FAggregatorEvaluateParameters EvaluateParameters;
	EvaluateParameters.SourceTags=SourceTags;
	EvaluateParameters.TargetTags=TargetTags;
	
	float Intelligence=0.f;
	GetCapturedAttributeMagnitude(IntelligenceDef,Spec,EvaluateParameters,Intelligence);
	
	ICombatInterface* CombatInterface = Cast<ICombatInterface>(Spec.GetContext().GetSourceObject());
	const int32 PlayerLevel=CombatInterface->GetPlayerLevel();
	
	return 50.f+2.5f*Intelligence+15.f*PlayerLevel; 
}
