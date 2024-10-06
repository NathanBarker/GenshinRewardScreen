// Nathan Barker GenshinRewardScreen Personal Training Project. 


#include "DetailsPanel.h"

#include "ObjectiveItem.h"


void UDetailsPanel::InitialiseDetailsPanel(const FDetailsPanelMessage& InMessage) const
{
	QuestTitle->SetText(FText::FromString(InMessage.QuestTitle));
	QuestDescription->SetText(FText::FromString(InMessage.QuestDescription));
	QuestProgression->SetProgression(InMessage.QuestProgress);
	ObjectivesListView->ClearListItems();

	for (const TPair<FString, int> Objective : InMessage.ObjectiveDetails)
	{
		UObjectiveItem* ObjectiveItem = NewObject<UObjectiveItem>();
		ObjectiveItem->ObjectiveText = Objective.Key;
		ObjectivesListView->AddItem(ObjectiveItem);
	}
}
