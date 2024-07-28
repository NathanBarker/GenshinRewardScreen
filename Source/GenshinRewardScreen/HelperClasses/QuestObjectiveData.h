#pragma once

class QuestObjectiveData
{
public:

	static TPair<FString, int> GenerateRandomQuestData(const FString& ObjectiveName, const int& MaxSubTaskAmount);
};
