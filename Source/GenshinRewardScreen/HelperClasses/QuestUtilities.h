// Nathan Barker GenshinRewardScreen Personal Training Project. 

#pragma once

#include "GenshinRewardScreen/GameData/QuestModel.h"
#include "GenshinRewardScreen/UI/Quests/QuestEntryItem.h"

class QuestObjectiveData
{
public:
	static TArray<UQuestEntryItem*> CreateQuests(TArray<FQuest>& QuestRows,
	                                             const int32& MaxSubTaskAmount,
	                                             const int32& ExperienceRewardMax,
	                                             const int32& ExperienceRewardMin,
	                                             TArray <int32>& MaxCurrencyRewards, TArray<int32>& MinCurrencyRewards);

	static TPair<FString, int32> GenerateRandomQuestData(const FString& ObjectiveName, const int32& MaxSubTaskAmount);
	static TMap<FString, int32> GenerateRandomQuestObjectives(const FQuest& Quest, const int32& MaxSubTaskAmount);
	static TArray<FReward> GenerateQuestRewards(TArray <int32>& MaxCurrencyRewards, TArray<int32>& MinCurrencyRewards);
	static float GetQuestProgess(const TMap<FString, int32>& QuestObjectives, const int32& MaxSubTaskAmount);
};
