// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestProgressionView.h"

void UQuestProgressionView::NativePreConstruct()
{
	Super::NativePreConstruct();
}

void UQuestProgressionView::SetProgression(const int& Progression) const
{
	QuestProgression->SetText(FText::FromString(FString::FromInt(Progression)));

	if(Progression != 0)
	{
		ProgressBar->SetPercent(Progression / 10);
	}
	else
	{
		ProgressBar->SetPercent(0);
	}
	
}
