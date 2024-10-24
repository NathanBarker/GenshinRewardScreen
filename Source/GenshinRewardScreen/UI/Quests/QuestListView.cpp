// Fill out your copyright notice in the Description page of Project Settings.

#include "QuestListView.h"
#include "GenshinRewardScreen/GameplayMessages/GameplayMessages.h"
#include "Input/CommonUIInputTypes.h"
#include "QuestEntryItem.h"
#include "QuestRewardView.h"

UE_DEFINE_GAMEPLAY_TAG(UI_Message_On_Quest_Selection_Changed, "UI.Message.On.Quest.Selection.Changed");
UE_DEFINE_GAMEPLAY_TAG(UI_Message_On_Quest_Claim, "UI.Message.On.Quest.Claim");

void UQuestListView::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	IUserObjectListEntry::NativeOnListItemObjectSet(ListItemObject);
	UQuestEntryItem* Item = Cast<UQuestEntryItem>(ListItemObject);

	QuestTitle->SetText(FText::FromString(Item->Name));
	WBP_QuestProgression->SetProgression(Item->Progress);

	SetRewardsWidgets(Item);
	QuestEntryItem = Item;

	MessageSubsystem = UGameplayMessageSubsystem::Get(this);

	CompletedBg->SetVisibility(Item->isCompleted ? ESlateVisibility::HitTestInvisible : ESlateVisibility::Collapsed);
	ProgressSwitcher->SetActiveWidgetIndex(Item->isCompleted);
}

void UQuestListView::NativeConstruct()
{
	Super::NativeConstruct();
	for (int i = 0; i < ECurrency::Num; i++)
	{
		UQuestRewardView* RewardView = CreateWidget<UQuestRewardView>(this, QuestRewardTemplate);
		if (IsValid(RewardView))
		{
			RewardsContainer->AddChild(RewardView);
			RewardView->SetVisibility(ESlateVisibility::Collapsed);
			FMargin RewardViewPadding = {0, 0, 10, 0};
			RewardView->SetPadding(RewardViewPadding);
		}
	}
}

void UQuestListView::NativeOnSelected(bool bBroadcast)
{
	Super::NativeOnSelected(bBroadcast);

	if (DetailsInputHandle.IsValid()) return;

	if (!DetailsInput.IsNull())
	{
		FBindUIActionArgs BindArgs(DetailsInput, true,
		                           FSimpleDelegate::CreateUObject(this, &UQuestListView::NativeOnClicked));

		BindArgs.InputMode = ECommonInputMode::Menu;
		DetailsInputHandle = RegisterUIActionBinding(BindArgs);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Details Input is Null, check this view's properties to ensure it is set"));
	}

	if (!ClaimInput.IsNull())
	{
		if (!QuestEntryItem->isCompleted && QuestEntryItem->Progress == 1)
		{
			FBindUIActionArgs BindArgs(ClaimInput, true,
			                           FSimpleDelegate::CreateUObject(this, &UQuestListView::ClaimRewardCallback));
			BindArgs.InputMode = ECommonInputMode::Menu;
			ClaimInputHandle = RegisterUIActionBinding(BindArgs);
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Claim Input is Null, check this view's properties to ensure it is set"));
	}
}

void UQuestListView::NativeOnClicked()
{
	Super::NativeOnClicked();

	FDetailsPanelMessage OutgoingMessage;

	// Define Message Data
	OutgoingMessage.QuestTitle = QuestEntryItem->Name;
	OutgoingMessage.QuestDescription = QuestEntryItem->Description;
	OutgoingMessage.Rewards = QuestEntryItem->Rewards;
	OutgoingMessage.ObjectiveDetails = QuestEntryItem->Objectives;
	OutgoingMessage.QuestProgress = QuestEntryItem->Progress;
	OutgoingMessage.XP = QuestEntryItem->Experience;

	MessageSubsystem->BroadcastMessage(UI_Message_On_Quest_Selection_Changed, OutgoingMessage);
}

void UQuestListView::NativeOnDeselected(bool bBroadcast)
{
	Super::NativeOnDeselected(bBroadcast);
	DetailsInputHandle.Unregister();
	ClaimInputHandle.Unregister();
}

void UQuestListView::SetRewardsWidgets(UQuestEntryItem* Item)
{
	for (UWidget* RewardWidget : RewardsContainer->GetAllChildren())
	{
		UQuestRewardView* RewardView = Cast<UQuestRewardView>(RewardWidget);
		RewardView->SetVisibility(ESlateVisibility::Collapsed);
	}

	Item->Rewards.Sort();

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
			if (!RewardBackground || !RewardIcon)
			{
				UE_LOG(LogTemp, Error, TEXT("Reward View failed to get created"));
				return;
			}
			RewardView->InitializeReward(RewardBackground, RewardIcon, Reward.CurrencyAmount);
			RewardView->SetVisibility(ESlateVisibility::HitTestInvisible);
			RewardsContainer->AddChild(RewardView);
		}
	}
}

void UQuestListView::ClaimRewardCallback()
{
	// Displays "Completed" text in the widget
	ProgressSwitcher->SetActiveWidgetIndex(1);

	FClaimMessage ClaimMessage;
	ClaimMessage.QuestItem = Cast<UObject>(QuestEntryItem);

	CompletedBg->SetVisibility(ESlateVisibility::HitTestInvisible);
	MessageSubsystem->BroadcastMessage(UI_Message_On_Quest_Claim, ClaimMessage);
}
