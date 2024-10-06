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

	float QuestProgress = 0;

	TArray<FReward> Rewards;

	int XP = 0;

	TMap<FString, int> ObjectiveDetails;
};
