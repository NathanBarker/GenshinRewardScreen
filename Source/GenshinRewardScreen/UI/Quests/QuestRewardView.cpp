// Nathan Barker GenshinRewardScreen Personal Training Project. 

#include "QuestRewardView.h"

#include "CommonUI/Public/CommonLazyImage.h"
#include "Components/TextBlock.h"

void UQuestRewardView::InitializeReward(const TSoftObjectPtr<UTexture2D>& Background,
                                        const TSoftObjectPtr<UTexture2D>& Icon, const int32& Amount)
{
	RewardIcon->SetBrushFromLazyTexture(Icon);
	RewardBackground->SetBrushFromLazyTexture(Background);
	RewardAmount->SetText(FText::AsNumber(Amount));
}
