// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestListView.h"
#include "QuestEntryItem.h"
#include "QuestRewardView.h"

void UQuestListView::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	IUserObjectListEntry::NativeOnListItemObjectSet(ListItemObject);
	UQuestEntryItem* Item = Cast<UQuestEntryItem>(ListItemObject);
	QuestTitle->SetText(FText::FromString(Item->Name));
	WBP_QuestProgression->SetProgression(Item->Progress);
	SetRewardsWidgets(Item);
}

void UQuestListView::NativeConstruct()
{
	Super::NativeConstruct();
	for (int i = 0; i < 3; i++)
	{
		UQuestRewardView* RewardView = CreateWidget<UQuestRewardView>(this, QuestRewardTemplate);
		if (IsValid(RewardView))
		{
			RewardsContainer->AddChild(RewardView);
			RewardView->SetVisibility(ESlateVisibility::Collapsed);
			FMargin RewardViewPadding = {0,0,10,0};
			RewardView->SetPadding(RewardViewPadding);
		}
	}
}

void UQuestListView::SetRewardsWidgets(const UQuestEntryItem* Item)
{
	for (UWidget* RewardWidget : RewardsContainer->GetAllChildren())
	{
		UQuestRewardView* RewardView = Cast<UQuestRewardView>(RewardWidget);
		RewardView->SetVisibility(ESlateVisibility::Collapsed);
	}
	
	for (const FReward Reward : Item->Rewards)
	{
		UQuestRewardView* RewardView = Cast<UQuestRewardView>(RewardsContainer->GetAllChildren()[Reward.CurrencyType]);
		if (IsValid(RewardView))
		{
			UTexture2D* RewardBackground = nullptr;
			UTexture2D* RewardIcon = nullptr;

			if (RewardBackgrounds.IsEmpty())
			{
				UE_LOG(LogTemp, Error,
				       TEXT("Reward Background array is empty, enter reward backgrounds inside the WBP_QuestListEntry"
				       ));
			}
			else
			{
				RewardBackground = RewardBackgrounds[Reward.CurrencyType];
			}

			if (RewardIcons.IsEmpty())
			{
				UE_LOG(LogTemp, Error,
				       TEXT("Reward Icons array is empty, enter reward icons inside the WBP_QuestListEntry"));
			}
			else
			{
				RewardIcon = RewardIcons[Reward.CurrencyType];
			}
			if (!RewardBackground || !RewardIcon) return;
			RewardView->InitializeReward(RewardBackground, RewardIcon, Reward.CurrencyAmount);
			RewardView->SetVisibility(ESlateVisibility::HitTestInvisible);
			RewardsContainer->AddChild(RewardView);
		}
		UE_LOG(LogTemp, Error, TEXT("Reward View failed to get created"));
	}
}
