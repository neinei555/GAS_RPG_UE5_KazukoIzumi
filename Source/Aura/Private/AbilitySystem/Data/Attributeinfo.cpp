// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Data/Attributeinfo.h"

FKklAttributeInfo UAttributeinfo::FindAttributeInfoForTag(const FGameplayTag& AttributeTag, bool bLogNotFound) const
{
	for (const FKklAttributeInfo& Info : AttributeInformation)
		{
			if (Info.AttributeTag == AttributeTag)
			{
				return Info;
			}
		}
	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Warning, TEXT("AttributeInfo not found for tag: %s"), *AttributeTag.ToString());
	}
	return FKklAttributeInfo();
}
