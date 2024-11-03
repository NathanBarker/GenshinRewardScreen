// Nathan Barker GenshinRewardScreen Personal Training Project. 

#include "QuestUtilities.h"

TArray<UQuestEntryItem*> QuestObjectiveData::CreateQuests(TArray<FQuest>& QuestRows, const int32& MaxSubTaskAmount,
                                                          const int32& ExperienceRewardMax,
                                                          const int32& ExperienceRewardMin,
                                                          TArray<int32>& MaxCurrencyRewards,
                                                          TArray<int32>& MinCurrencyRewards
)
{
	TArray<UQuestEntryItem*> Quests = {};

	for (const FQuest& Quest : QuestRows)
	{
		UQuestEntryItem* QuestObject = NewObject<UQuestEntryItem>();
		QuestObject->Name = Quest.Name;
		QuestObject->Description = Quest.Description;
		QuestObject->Objectives = GenerateRandomQuestObjectives(Quest, MaxSubTaskAmount);
		QuestObject->Progress = GetQuestProgess(QuestObject->Objectives, MaxSubTaskAmount);
		QuestObject->Experience = rand() % ExperienceRewardMax + ExperienceRewardMin;
		QuestObject->Rewards = GenerateQuestRewards(MaxCurrencyRewards, MinCurrencyRewards);
		
		Quests.Emplace(QuestObject);
	}
	return Quests;
}

TPair<FString, int32> QuestObjectiveData::GenerateRandomQuestData(const FString& ObjectiveName,
                                                                  const int32& MaxSubTaskAmount)
{
	TPair<FString, int32>* ObjectiveDetailEntry = new TPair<FString, int32>;
	ObjectiveDetailEntry->Key = ObjectiveName;
	ObjectiveDetailEntry->Value = rand() % MaxSubTaskAmount + 1;
	return *ObjectiveDetailEntry;
}

TMap<FString, int32> QuestObjectiveData::GenerateRandomQuestObjectives(const FQuest& Quest,
                                                                       const int32& MaxSubTaskAmount)
{
	TMap<FString, int32> ObjectiveDetails;
	for (int32 i = 0; i < Quest.Objectives.Num(); i++)
	{
		ObjectiveDetails.Add(GenerateRandomQuestData(
			Quest.Objectives[i], MaxSubTaskAmount));
	}
	return ObjectiveDetails;
}

TArray<FReward> QuestObjectiveData::GenerateQuestRewards(TArray<int32>& MaxCurrencyRewards,
                                                         TArray<int32>& MinCurrencyRewards)
{
	TArray<FReward> Rewards;
	int32 RewardCount = rand() % 4;
	TArray<ECurrency> AddedCurrencyTypes = {};

	for (int32 i = 0; i <= RewardCount; i++)
	{
		// -1 here to avoid choosing XP, we have already defined XP
		ECurrency RewardEntryCurrencyType = static_cast<ECurrency>(rand() % (Num - 1));

		if (AddedCurrencyTypes.Contains(RewardEntryCurrencyType)) continue;

		FReward Reward = FReward(RewardEntryCurrencyType,
		                         MaxCurrencyRewards[RewardEntryCurrencyType],
		                         MinCurrencyRewards[RewardEntryCurrencyType]);
		AddedCurrencyTypes.Emplace(RewardEntryCurrencyType);
		Rewards.Emplace(Reward);
	}
	return Rewards;
}

float QuestObjectiveData::GetQuestProgess(const TMap<FString, int32>& QuestObjectives, const int32& MaxSubTaskAmount)
{
	float Progress = 0.0f;

	for (const TPair<FString, int32>& ObjectiveDetail : QuestObjectives)
	{
		if (ObjectiveDetail.Value == MaxSubTaskAmount) Progress++;
	}
	float ObjectiveCount = QuestObjectives.Num();
	return Progress / ObjectiveCount;
}
