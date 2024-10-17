// Nathan Barker GenshinRewardScreen Personal Training Project. 

#include "MainScreen.h"

#include "Currency/CurrencyView.h"
#include "GenshinRewardScreen/HelperClasses/QuestObjectiveData.h"

void UMainScreen::NativeConstruct()
{
	Super::NativeConstruct();
	
	PlayerInventory = NewObject<UInventory>();
	
	if (QuestDataObjects.IsEmpty())
	{
		GenerateQuestData();
	}
}

void UMainScreen::NativeOnActivated()
{
	Super::NativeOnActivated();

	GetDesiredFocusTarget()->SetFocus();
	
	for (int i = 0; i < CurrencyHorizontalLayout->GetAllChildren().Num(); i++)
	{
		if (UCurrencyView* CurrencyView = Cast<UCurrencyView>(CurrencyHorizontalLayout->GetAllChildren()[i]))
		{
			CurrencyViews.Emplace(CurrencyView);
			
			if (IsValid(PlayerInventory))
			{
				CurrencyView->SetCurrencyText(PlayerInventory->GetCurrencyAmount(i));
			}
		}
		else
		{
			UE_LOG(LogTemp, Error,
			       TEXT("Casting of Currency UWidget Type failed, widget will not be added to CurrencyViews array"));
			return;
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
