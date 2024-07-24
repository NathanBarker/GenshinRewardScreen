// Fill out your copyright notice in the Description page of Project Settings.


#include "MainScreen.h"

#include "Currency/CurrencyView.h"
#include "Quests/QuestEntryItem.h"
#include "Quests/QuestRewards.h"

void UMainScreen::NativeOnActivated()
{
	Super::NativeOnActivated();
	GenerateQuestData();

	// Get all CurrencyViews
	for (uint8 i = 0; i < CurrencyHorizontalLayout->GetAllChildren().Num(); i++)
	{
		if (UCurrencyView* CurrencyView = Cast<UCurrencyView>(CurrencyHorizontalLayout->GetAllChildren()[i]))
		{
			CurrencyViews.Emplace(CurrencyView);
			CurrencyView->InitCurrencyView();
		}
		else
		{
			UE_LOG(LogTemp, Error,
			       TEXT("Casting of Currency UWidget Type failed, widget will not be added to CurrencyViews array"));
		}
	}

	UWidget* DesiredWidget = GetDesiredFocusTarget();
	if (IsValid(DesiredWidget))
	{
		DesiredWidget->SetFocus();
	}
}

void UMainScreen::GenerateQuestData()
{
	TArray<FName> RowNames = QuestDataTable->GetRowNames();
	for (const FName QuestData : RowNames)
	{
		FQuest QuestEntryObject = *QuestDataTable->FindRow<FQuest>(QuestData, "");
		QuestRows.Emplace(QuestEntryObject);
	}
	DisplayQuests();
}

void UMainScreen::DisplayQuests()
{
	for (const FQuest& Quest : QuestRows)
	{
		UQuestEntryItem* QuestObject = NewObject<UQuestEntryItem>();
		QuestObject->Name = Quest.Name;
		QuestObject->Description = Quest.Description;

		TArray<TPair<FString, int>>* ObjectiveDetails = new TArray<TPair<FString, int>>;
		for (int i = 0; i < Quest.Objectives.Num(); i++)
		{
			const FString QuestName = Quest.Objectives[i];
			TPair<FString, int>* ObjectiveDetailEntry = new TPair<FString, int>;
			ObjectiveDetailEntry->Key = QuestName;
			ObjectiveDetailEntry->Value = rand() % MaxSubTaskAmount + 1;
			ObjectiveDetails->Emplace(*ObjectiveDetailEntry);
		}
		QuestObject->Objectives = *ObjectiveDetails;

		int CurrentObjectiveProgress = 0;
		int ObjectiveCount = QuestObject->Objectives.Num();

		for (const TPair<FString, int>& ObjectiveDetail : QuestObject->Objectives)
		{
			if (ObjectiveDetail.Value == MaxSubTaskAmount) CurrentObjectiveProgress++;
		}

		if (CurrentObjectiveProgress != 0)
		{
			QuestObject->Progress = ObjectiveCount / CurrentObjectiveProgress;
		}
		else
		{
			QuestObject->Progress = 0;
		}
		QuestObject->Experience = rand() % ExperienceRewardMax + ExperienceRewardMin;

		int RewardCount = rand() % 3;
		for (int i = 0; i <= RewardCount; i++)
		{
			FReward Reward = {};
			Reward.CurrencyType = static_cast<ECurrency>(rand() % ECurrency::Num + 1);
			switch (Reward.CurrencyType)
			{
			case Crystal:
				{
					AllocateCurrencyAmount(Reward, CrystalRewardMax, CrystalRewardMin);
					break;
				}
			case Ruby:
				{
					AllocateCurrencyAmount(Reward, RubyRewardMax, RubyRewardMin);
					break;
				}
			case PrimoGem:
				{
					AllocateCurrencyAmount(Reward, PrimogenRewardMax, PrimogemRewardMin);
					break;
				}
			default: break;
			}
			QuestObject->Rewards.Emplace(Reward);
		}
		QuestDataObjects.Emplace(QuestObject);
	}
	QuestListView->SetListItems(QuestDataObjects);
}

void UMainScreen::AllocateCurrencyAmount(FReward& Reward, const int MaxAmount, const int MinAmount)
{
	Reward.Amount = rand() % MaxAmount + MinAmount;
}

UWidget* UMainScreen::NativeGetDesiredFocusTarget() const
{
	return QuestListView;
}
