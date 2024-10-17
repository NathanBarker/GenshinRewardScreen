// Nathan Barker GenshinRewardScreen Personal Training Project. 

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
	
	FString Name = "";
	
	FString Description = "";
	
	TMap<FString, int> Objectives = {};
	
	float Progress = 0;
	
	TArray<FReward> Rewards = {};
	
	int Experience = 0;

	bool operator< (const UQuestEntryItem& Other) const
	{
		return Other.Progress < Progress;
	}
};
