#include "QuestObjectiveData.h"

TArray<UQuestEntryItem*> QuestObjectiveData::CreateQuests(TArray<FQuest>& QuestRows, const int& MaxSubTaskAmount,
                                                          const int& ExperienceRewardMax,
                                                          const int& ExperienceRewardMin,
                                                          TArray<int>& MaxCurrencyRewards,
                                                          TArray<int>& MinCurrencyRewards
)
{
	TArray<UQuestEntryItem*> QuestObjects = {};

	for (const FQuest& Quest : QuestRows)
	{
		UQuestEntryItem* QuestObject = NewObject<UQuestEntryItem>();
		QuestObject->Name = Quest.Name;
		QuestObject->Description = Quest.Description;

		TMap<FString, int> ObjectiveDetails;
		for (int i = 0; i < Quest.Objectives.Num(); i++)
		{
			ObjectiveDetails.Add(GenerateRandomQuestData(
				Quest.Objectives[i], MaxSubTaskAmount));
		}
		QuestObject->Objectives = ObjectiveDetails;

		float CurrentObjectiveProgress = 0.0f;
		float ObjectiveCount = QuestObject->Objectives.Num();

		for (const TPair<FString, int>& ObjectiveDetail : QuestObject->Objectives)
		{
			if (ObjectiveDetail.Value == MaxSubTaskAmount) CurrentObjectiveProgress++;
		}

		if (CurrentObjectiveProgress != 0.0f)
		{
			float Progress = CurrentObjectiveProgress / ObjectiveCount;
			QuestObject->Progress = Progress;
		}
		else
		{
			QuestObject->Progress = 0;
		}
		QuestObject->Experience = rand() % ExperienceRewardMax + ExperienceRewardMin;

		int RewardCount = rand() % 4;
		for (int i = 0; i <= RewardCount; i++)
		{
			// -1 here to avoid choosing XP, we have already defined XP
			ECurrency RewardEntryCurrencyType = static_cast<ECurrency>(rand() % (Num - 1));
			bool AlreadyHasRewardType = false;
			for (const FReward& Reward : QuestObject->Rewards)
			{
				if (Reward.CurrencyType == RewardEntryCurrencyType)
				{
					AlreadyHasRewardType = true;
				}
			}
			if (AlreadyHasRewardType) continue;
			FReward Reward = FReward(RewardEntryCurrencyType, MaxCurrencyRewards[RewardEntryCurrencyType],
			                         MinCurrencyRewards[RewardEntryCurrencyType]);
			QuestObject->Rewards.Emplace(Reward);
		}
		QuestObjects.Emplace(QuestObject);
	}
	return QuestObjects;
}

TPair<FString, int> QuestObjectiveData::GenerateRandomQuestData(const FString& ObjectiveName,
                                                                const int& MaxSubTaskAmount)
{
	TPair<FString, int>* ObjectiveDetailEntry = new TPair<FString, int>;
	ObjectiveDetailEntry->Key = ObjectiveName;
	ObjectiveDetailEntry->Value = rand() % MaxSubTaskAmount + 1;
	return *ObjectiveDetailEntry;
}
