// Nathan Barker GenshinRewardScreen Personal Training Project. 

#pragma once

#include "CoreMinimal.h"
#include "QuestRewards.h"
#include "UObject/Object.h"
#include "QuestEntryItem.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class GENSHINREWARDSCREEN_API UQuestEntryItem : public UObject
{
	GENERATED_BODY()

public:
	UQuestEntryItem() = default;
	
	FString Name = "";
	
	FString Description = "";
	
	TMap<FString, int32> Objectives = {};
	
	float Progress = 0.0f;
	
	TArray<FReward> Rewards = {};
	
	int32 Experience = 0;

	bool isCompleted = false;

	bool operator< (const UQuestEntryItem& Other) const
	{
		return Other.Progress < Progress;
	}
};
