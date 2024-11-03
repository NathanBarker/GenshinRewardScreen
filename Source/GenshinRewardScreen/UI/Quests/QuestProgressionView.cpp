// Nathan Barker GenshinRewardScreen Personal Training Project. 

#include "QuestProgressionView.h"

void UQuestProgressionView::NativePreConstruct()
{
	Super::NativePreConstruct();
}

void UQuestProgressionView::SetProgression(const float& Progression) const
{
	const int ProgressionAmount = Progression * 100;
	const FText& ProgressionText = FText::FromString(FString::FromInt(ProgressionAmount) + "%");
	QuestProgression->SetText(ProgressionText);
	ProgressBar->SetPercent(Progression);
}
