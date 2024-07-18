// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestListView.h"

#include "QuestEntryItem.h"

void UQuestListView::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	IUserObjectListEntry::NativeOnListItemObjectSet(ListItemObject);
	UQuestEntryItem* Item = Cast<UQuestEntryItem>(ListItemObject);
	QuestTitle->SetText(FText::FromString(Item->QuestName));
}
