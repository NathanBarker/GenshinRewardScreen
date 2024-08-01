// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestRewardView.h"

void UQuestRewardView::InitializeReward(UTexture2D* Background, UTexture2D* Icon, const int& Amount) const
{
	RewardBackground->SetBrushFromTexture(Background);
	RewardIcon->SetBrushFromTexture(Icon);
	RewardAmount->SetText(FText::FromString(FString::FromInt(Amount)));
}
