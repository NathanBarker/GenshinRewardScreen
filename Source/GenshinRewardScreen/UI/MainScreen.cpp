// Fill out your copyright notice in the Description page of Project Settings.


#include "MainScreen.h"

#include "Currency/CurrencyView.h"
#include "Quests/QuestEntryItem.h"

void UMainScreen::NativeConstruct()
{
	Super::NativeConstruct();
	QuestModelData = new QuestModel();
	TArray<FName> RowNames = QuestDataTable->GetRowNames();
	GenerateQuestData(RowNames);

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

void UMainScreen::GenerateQuestData(const TArray<FName>& RowNames)
{
	for (auto QuestData : RowNames)
	{
		FQuest* QuestEntryObject = QuestDataTable->FindRow<FQuest>(QuestData, "");
		QuestRows.Emplace(QuestEntryObject);
	}
	DisplayQuests();
}

void UMainScreen::DisplayQuests()
{
	for (const FQuest* Quest : QuestRows)
	{
		UQuestEntryItem* QuestObject = NewObject<UQuestEntryItem>();
		QuestObject->QuestName = Quest->Name;
		QuestObject->QuestDescription = Quest->Description;
		QuestDataObjects.Emplace(QuestObject);
	}
	
	QuestListView->SetListItems(QuestDataObjects);
}
