// Nathan Barker GenshinRewardScreen Personal Training Project. 


#include "MainScreen.h"

#include "Currency/CurrencyView.h"
#include "GenshinRewardScreen/HelperClasses/QuestObjectiveData.h"
#include "Quests/QuestEntryItem.h"
#include "Quests/QuestRewards.h"


void UMainScreen::NativeOnActivated()
{
	Super::NativeOnActivated();
	if (QuestDataObjects.IsEmpty())
	{
		GenerateQuestData();
	}
	GetDesiredFocusTarget()->SetFocus();

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
	QuestDataObjects = QuestObjectiveData::CreateQuests(QuestRows, MaxSubTaskAmount, ExperienceRewardMax,
	                                                    ExperienceRewardMin, MaxCurrencyRewards, MinCurrencyRewards);

	QuestDataObjects.Sort();
	QuestList->SetListItems(QuestDataObjects);
}

UWidget* UMainScreen::NativeGetDesiredFocusTarget() const
{
	QuestList->SetFocus();
	return QuestList;
}
