#pragma once

#include "GenshinRewardScreen/UI/Quests/QuestRewards.h"
#include "GameplayMessages.generated.h"

USTRUCT()
struct FDetailsPanelMessage
{
	GENERATED_BODY()

	FString QuestTitle = "";

	FString QuestDescription = "";

	float QuestProgress = 0;

	TArray<FReward> Rewards = {};

	int XP = 0;

	TMap<FString, int> ObjectiveDetails = {};
};

USTRUCT()
struct FClaimMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TObjectPtr<UObject> QuestItem = nullptr;
	
};
