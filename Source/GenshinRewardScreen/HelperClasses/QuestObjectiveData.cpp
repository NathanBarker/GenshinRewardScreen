#include "QuestObjectiveData.h"

TPair<FString, int> QuestObjectiveData::GenerateRandomQuestData(const FString& ObjectiveName, const int& MaxSubTaskAmount)
{
	TPair<FString, int>* ObjectiveDetailEntry = new TPair<FString, int>;
	ObjectiveDetailEntry->Key = ObjectiveName;
	ObjectiveDetailEntry->Value = rand() % MaxSubTaskAmount + 1;
	return *ObjectiveDetailEntry;
}
