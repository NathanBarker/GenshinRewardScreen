// Nathan Barker GenshinRewardScreen Personal Training Project. 


#include "QuestRewardView.h"

void UQuestRewardView::InitializeReward(UTexture2D* Background, UTexture2D* Icon, const int32& Amount) const
{
	RewardBackground->SetBrushFromTexture(Background);
	RewardIcon->SetBrushFromTexture(Icon);
	RewardAmount->SetText(FText::FromString(FString::FromInt(Amount)));
}
