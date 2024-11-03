// Nathan Barker GenshinRewardScreen Personal Training Project. 

#include "DetailsPanel.h"
#include "ObjectiveItem.h"

void UDetailsPanel::InitialiseDetailsPanel(const FDetailsPanelMessage& InMessage) const
{
	QuestTitle->SetText(InMessage.QuestTitle);
	QuestDescription->SetText(InMessage.QuestDescription);
	QuestProgression->SetProgression(InMessage.QuestProgress);
	ObjectivesListView->ClearListItems();

	for (const TPair<FString, int32> Objective : InMessage.ObjectiveDetails)
	{
		UObjectiveItem* ObjectiveItem = NewObject<UObjectiveItem>();
		ObjectiveItem->ObjectiveText = Objective.Key;
		ObjectivesListView->AddItem(ObjectiveItem);
	}

	FMargin RewardViewPadding = {0, 0, 50, 0};
	XPReward->InitialiseReward(XP, InMessage.XP);
	XPReward->SetVisibility(ESlateVisibility::Visible);
	XPReward->SetPadding(RewardViewPadding);
	RewardsContainer->AddChild(XPReward);

	for (const FReward& Reward : InMessage.Rewards)
	{
		URewardView* RewardView = CreateWidget<URewardView>(GetWorld(), RewardTemplate);
		if (IsValid(RewardView))
		{
			RewardsContainer->AddChild(RewardView);
			RewardView->SetVisibility(ESlateVisibility::Visible);
			RewardView->SetPadding(RewardViewPadding);
			RewardView->InitialiseReward(Reward.CurrencyType, Reward.CurrencyAmount);
		}
		else
		{
			UE_LOG(LogTemp, Error,
			       TEXT("Reward view inside details panel failed to be created"
			       ));
		}
	}
}

void UDetailsPanel::NativeOnDeactivated()
{
	Super::NativeOnDeactivated();
	RewardsContainer->ClearChildren();
}