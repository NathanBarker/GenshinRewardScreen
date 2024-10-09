#pragma once

#include "GenshinRewardScreen/DataModel/QuestModel.h"
#include "GenshinRewardScreen/UI/Quests/QuestEntryItem.h"

class QuestObjectiveData
{
public:
	static TArray<UQuestEntryItem*> CreateQuests(TArray<FQuest>& QuestRows, const int& MaxSubTaskAmount, const int& ExperienceRewardMax, const int& ExperienceRewardMin, TArray
	                                             <int>& MaxCurrencyRewards, TArray<int>& MinCurrencyRewards);
	static TPair<FString, int> GenerateRandomQuestData(const FString& ObjectiveName, const int& MaxSubTaskAmount);
};
