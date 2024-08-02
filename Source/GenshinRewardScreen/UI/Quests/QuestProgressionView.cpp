// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestProgressionView.h"

void UQuestProgressionView::NativePreConstruct()
{
	Super::NativePreConstruct();
}

void UQuestProgressionView::SetProgression(const float& Progression) const
{
	const int ProgressionAmount = Progression * 100;
	const FText& ProgressionText = FText::FromString(FString::FromInt(ProgressionAmount) + "%") ;
	QuestProgression->SetText(ProgressionText);

	if(Progression != 0)
	{
		ProgressBar->SetPercent(Progression);
	}
	else
	{
		ProgressBar->SetPercent(0);
	}
	
}
