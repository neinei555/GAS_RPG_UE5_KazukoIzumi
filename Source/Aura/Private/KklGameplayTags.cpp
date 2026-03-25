// Fill out your copyright notice in the Description page of Project Settings.


#include "KklGameplayTags.h"
#include "GameplayTagsManager.h"
FKklGameplayTags FKklGameplayTags::GameplayTags;

void FKklGameplayTags::InitializeNativeGameplayTags()
{
	/*
	 * Primary Attributes
	 */
    GameplayTags.Attributes_Primary_Strength=UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attribute.Primary.Strength"),
		FString("力量")
		);

	GameplayTags.Attributes_Primary_intelligence=UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attribute.Primary.Intelligence"),
		FString("智力")
		);

	GameplayTags.Attributes_Primary_Resilience=UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attribute.Primary.Resilience"),
		FString("韧性")
		);

	GameplayTags.Attributes_Primary_Vigor=UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attribute.Primary.Vigor"),
		FString("活力")
		);


	/*
	 * Secondary Attributes
	 */
    GameplayTags.Attributes_Secondary_Armor=UGameplayTagsManager::Get().AddNativeGameplayTag(
    FName("Attribute.Secondary.Armor"),
    FString("降低受伤，增加格挡机会")
    );

	GameplayTags.Attributes_Secondary_ArmorPenetration=UGameplayTagsManager::Get().AddNativeGameplayTag(
	  FName("Attribute.Secondary.ArmorPenetration"),
	  FString("降低Armor")
	  );

	GameplayTags.Attributes_Secondary_BlockChance=UGameplayTagsManager::Get().AddNativeGameplayTag(
	  FName("Attribute.Secondary.BlockChance"),
	  FString("格挡机会")
	  );

	GameplayTags.Attributes_Secondary_CriticalHitChance=UGameplayTagsManager::Get().AddNativeGameplayTag(
	  FName("Attribute.Secondary.CriticalHitChance"),
	  FString("暴击机会")
	  );

	GameplayTags.Attributes_Secondary_CriticalHitDamage=UGameplayTagsManager::Get().AddNativeGameplayTag(
	  FName("Attribute.Secondary.CriticalHitDamage"),
	  FString("暴击伤害")
	  );

	GameplayTags.Attributes_Secondary_CriticalHitDamage=UGameplayTagsManager::Get().AddNativeGameplayTag(
	  FName("Attribute.Secondary.CriticalHitResistance"),
	  FString("暴击抗性")
	  );

	GameplayTags.Attributes_Secondary_HealthRegeneration=UGameplayTagsManager::Get().AddNativeGameplayTag(
	  FName("Attribute.Secondary.HealthRegeneration"),
	  FString("生命恢复")
	  );

	GameplayTags.Attributes_Secondary_ManaRegeneration=UGameplayTagsManager::Get().AddNativeGameplayTag(
	  FName("Attribute.Secondary.ManaRegeneration"),
	  FString("法力恢复")
	  );

	GameplayTags.Attributes_Secondary_MaxHealth=UGameplayTagsManager::Get().AddNativeGameplayTag(
	  FName("Attribute.Secondary.MaxHealth"),
	  FString("最大生命")
	  );

	GameplayTags.Attributes_Secondary_MaxMana=UGameplayTagsManager::Get().AddNativeGameplayTag(
	  FName("Attribute.Secondary.MaxMana"),
	  FString("最大法力")
	  );
	
	/*
	 * Input Tags
	 */
	GameplayTags.InputTag_LMB=UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("InputTag.LMB"),
	FString("鼠标左键")
	);
	
	GameplayTags.InputTag_RMB=UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("InputTag.RMB"),
	FString("鼠标右键")
	);
	
	GameplayTags.InputTag_1=UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("InputTag.1"),
	FString("1")
	);
	
	GameplayTags.InputTag_2=UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("InputTag.2"),
	FString("2")
	);
	
	GameplayTags.InputTag_3=UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("InputTag.3"),
	FString("3")
	);
	
	GameplayTags.InputTag_4=UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("InputTag.4"),
	FString("4")
	);
}
