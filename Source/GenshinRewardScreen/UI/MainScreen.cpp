// Fill out your copyright notice in the Description page of Project Settings.


#include "MainScreen.h"

#include "Currency/CurrencyView.h"
#include "Quests/QuestEntryItem.h"

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
		QuestObject->QuestName = Quest.Name;
		QuestObject->QuestDescription = Quest.Description;
		QuestDataObjects.Emplace(QuestObject);
	}

	QuestListView->SetListItems(QuestDataObjects);
}

UWidget* UMainScreen::NativeGetDesiredFocusTarget() const
{
	return QuestListView;
}
