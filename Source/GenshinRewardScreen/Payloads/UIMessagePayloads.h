// Nathan Barker GenshinRewardScreen Personal Training Project. 

#pragma once

#include "GenshinRewardScreen/UI/Quests/QuestRewards.h"
#include "UIMessagePayloads.generated.h"

USTRUCT()
struct FDetailsPanelMessage
{
	GENERATED_BODY()

	FText QuestTitle = FText::GetEmpty();

	FText QuestDescription = FText::GetEmpty();

	float QuestProgress = 0.0f;

	UPROPERTY()
	TArray<FReward> Rewards = {};

	int32 XP = 0;

	UPROPERTY()
	TMap<FString, int32> ObjectiveDetails = {};
};

USTRUCT()
struct FClaimMessage
{
	GENERATED_BODY()

	UPROPERTY(Transient)
	TObjectPtr<UObject> QuestItem = nullptr;
};
