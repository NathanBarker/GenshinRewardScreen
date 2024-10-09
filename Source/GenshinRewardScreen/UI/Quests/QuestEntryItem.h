// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "QuestRewards.h"
#include "UObject/Object.h"
#include "QuestEntryItem.generated.h"

/**
 * 
 */
UCLASS()
class GENSHINREWARDSCREEN_API UQuestEntryItem : public UObject
{
	GENERATED_BODY()

public:
	UQuestEntryItem() = default;
	UPROPERTY()
	FString Name;

	UPROPERTY()
	FString Description;
	
	TMap<FString, int> Objectives;

	UPROPERTY()
	float Progress = 0;

	UPROPERTY()
	TArray<FReward> Rewards;

	UPROPERTY()
	int Experience = 0;

	bool operator< (const UQuestEntryItem& Other) const
	{
		return Other.Progress < Progress;
	}
};
