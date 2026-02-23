// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/ModMagCalc/MMC_MaxHealth.h"

#include "AbilitySystem/KklAttributeSet.h"
#include "Interaction/CombatInterface.h"

UMMC_MaxHealth::UMMC_MaxHealth()
{
	Vigordef.AttributeToCapture=UKklAttributeSet::GetVigorAttribute();
	Vigordef.AttributeSource=EGameplayEffectAttributeCaptureSource::Target;
	Vigordef.bSnapshot=false;
	
	RelevantAttributesToCapture.Add(UMMC_MaxHealth::Vigordef);
}

float UMMC_MaxHealth::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
 	//Gather Tags from source and tafget
 	const FGameplayTagContainer* SourceTags=Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags=Spec.CapturedTargetTags.GetAggregatedTags();
	
	FAggregatorEvaluateParameters EvaluateParameters;
	EvaluateParameters.SourceTags=SourceTags;
	EvaluateParameters.TargetTags=TargetTags;
	
	float Vigor=0.f;
	GetCapturedAttributeMagnitude(Vigordef,Spec,EvaluateParameters,Vigor);
	
	ICombatInterface* CombatInterface = Cast<ICombatInterface>(Spec.GetContext().GetSourceObject());
	const int32 PlayerLevel=CombatInterface->GetPlayerLevel();
	
	return 80.f+2.5f*Vigor+10.f*PlayerLevel; 
}
