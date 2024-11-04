// Nathan Barker GenshinRewardScreen Personal Training Project. 

#include "DetailsPanel.h"

#include "Components/TextBlock.h"
#include "Components/HorizontalBox.h"
#include "Components/ListView.h"
#include "ObjectiveItem.h"

void UDetailsPanel::InitialiseDetailsPanel(const FDetailsPanelMessage& InMessage)
{
	if (IsValid(QuestTitle)) QuestTitle->SetText(InMessage.QuestTitle);
	if (IsValid(QuestDescription)) QuestDescription->SetText(InMessage.QuestDescription);
	if (IsValid(QuestProgression)) QuestProgression->SetProgression(InMessage.QuestProgress);
	if (IsValid(ObjectivesListView)) ObjectivesListView->ClearListItems();

	for (const TPair<FString, int32> Objective : InMessage.ObjectiveDetails)
	{
		UObjectiveItem* ObjectiveItem = NewObject<UObjectiveItem>();
		ObjectiveItem->ObjectiveText = Objective.Key;
		ObjectivesListView->AddItem(ObjectiveItem);
	}

	DisplayRewards(InMessage.XP, InMessage.Rewards);
}

void UDetailsPanel::NativeOnDeactivated()
{
	Super::NativeOnDeactivated();

	XPReward->SetVisibility(ESlateVisibility::Collapsed);
	for (UWidget* RewardView : RewardsContainer->GetAllChildren())
	{
		RewardView->SetVisibility(ESlateVisibility::Collapsed);
	}
}

void UDetailsPanel::DisplayRewards(const int32& XPAmount, const TArray<FReward>& Rewards)
{
	ConfigureReward(*XPReward, XP, XPAmount);
	for (int32 i = 0; i < Rewards.Num(); i++)
	{
		if (IsValid(RewardsContainer->GetChildAt(i)))
		{
			URewardView* RewardView = Cast<URewardView>(RewardsContainer->GetChildAt(i));
			ConfigureReward(*RewardView, Rewards[i].CurrencyType, Rewards[i].CurrencyAmount);
		}
		else if(IsValid(RewardTemplate))
		{
			URewardView* RewardView = CreateWidget<URewardView>(GetWorld(), RewardTemplate);
			ConfigureReward(*RewardView, Rewards[i].CurrencyType, Rewards[i].CurrencyAmount);
			RewardsContainer->AddChild(RewardView);
		}
		else UE_LOG(LogTemp, Error, TEXT("Reward view inside details panel failed to be created"));
	}
}

void UDetailsPanel::ConfigureReward(URewardView& RewardView, const ECurrency& CurrencyType, const int32 CurrencyAmount)
{
	RewardView.SetPadding(RewardViewPadding);
	RewardView.InitialiseReward(CurrencyType, CurrencyAmount);
	RewardView.SetVisibility(ESlateVisibility::HitTestInvisible);
}
