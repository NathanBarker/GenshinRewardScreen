#pragma once

#include "GenshinRewardScreen/UI/Quests/QuestRewards.h"
#include "GameplayMessages.generated.h"

USTRUCT()
struct FDetailsPanelMessage
{
	GENERATED_BODY()
	bool OpenDetailsPanel = false;

	FString QuestTitle = "";

	FString QuestDescription = "";

	int QuestProgress = 0;

	TArray<FReward> Rewards;

	TMap<FString, int> ObjectiveDetails;
};
