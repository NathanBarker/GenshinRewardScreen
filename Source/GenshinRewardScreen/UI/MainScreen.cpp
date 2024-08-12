// Nathan Barker GenshinRewardScreen Personal Training Project. 


#include "MainScreen.h"

#include "Currency/CurrencyView.h"
#include "GenshinRewardScreen/HelperClasses/QuestObjectiveData.h"
#include "Quests/QuestEntryItem.h"
#include "Quests/QuestRewards.h"
#include "Input/CommonUIInputTypes.h"

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

	InitialiseDetailInput();
}

void UMainScreen::GenerateQuestData()
{
	TArray<FName> RowNames = QuestDataTable->GetRowNames();
	for (const FName QuestData : RowNames)
	{
		FQuest QuestEntryObject = *QuestDataTable->FindRow<FQuest>(QuestData, "");
		QuestRows.Emplace(QuestEntryObject);
	}
	InitialiseQuests();
}

void UMainScreen::InitialiseQuests()
{
	for (const FQuest& Quest : QuestRows)
	{
		UQuestEntryItem* QuestObject = NewObject<UQuestEntryItem>();
		QuestObject->Name = Quest.Name;
		QuestObject->Description = Quest.Description;

		TArray<TPair<FString, int>> ObjectiveDetails;
		for (int i = 0; i < Quest.Objectives.Num(); i++)
		{
			TPair<FString, int> ObjectiveDetailEntry = QuestObjectiveData::GenerateRandomQuestData(
				Quest.Objectives[i], MaxSubTaskAmount);
			ObjectiveDetails.Emplace(ObjectiveDetailEntry);
		}
		QuestObject->Objectives = ObjectiveDetails;

		float CurrentObjectiveProgress = 0.0f;
		float ObjectiveCount = QuestObject->Objectives.Num();

		for (const TPair<FString, int>& ObjectiveDetail : QuestObject->Objectives)
		{
			if (ObjectiveDetail.Value == MaxSubTaskAmount) CurrentObjectiveProgress++;
		}

		// todo: check for 0 objectives
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

		int RewardCount = rand() % 3;
		for (int i = 0; i <= RewardCount; i++)
		{
			ECurrency RewardEntryCurrencyType = static_cast<ECurrency>(rand() % ECurrency::Num);
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
		QuestDataObjects.Emplace(QuestObject);
	}
	QuestList->SetListItems(QuestDataObjects);
}

void UMainScreen::InitialiseDetailInput()
{
	if (DetailsInputHandle.IsValid()) return;

	FBindUIActionArgs BindArgs (DetailsInput, true,
	                           FSimpleDelegate::CreateUObject(this, &UMainScreen::OpenDetailsPanel));

	BindArgs.InputMode = ECommonInputMode::Menu;
	DetailsInputHandle = RegisterUIActionBinding(BindArgs);
}

void UMainScreen::OpenDetailsPanel()
{
	UE_LOG(LogTemp, Error, TEXT("Opened Detail Panel"));
}


UWidget* UMainScreen::NativeGetDesiredFocusTarget() const
{
	return QuestList;
}
