// Nathan Barker GenshinRewardScreen Personal Training Project. 

#include "RewardView.h"

#include "CommonUI/Public/CommonLazyImage.h"
#include "Components/TextBlock.h"

void URewardView::InitialiseReward(const ECurrency& CurrencyType, const int32& Amount)
{
	XPText->SetVisibility(ESlateVisibility::Hidden);

	if (RewardBackgrounds.IsEmpty())
	{
		UE_LOG(LogTemp, Error,
		       TEXT("Reward Background array is empty, enter reward backgrounds inside the WBP_RewardView"
		       ));
	}
	else
	{
		BackgroundTexture = RewardBackgrounds[CurrencyType];
	}

	if (RewardIcons.IsEmpty())
	{
		UE_LOG(LogTemp, Error,
		       TEXT("Reward Icons array is empty, enter reward icons inside the WBP_RewardView"));
	}
	else
	{
		IconTexture = RewardIcons[CurrencyType];
	}

	RewardBackground->SetBrushFromLazyTexture(BackgroundTexture);
	RewardIcon->SetBrushFromLazyTexture(IconTexture);
	RewardAmount->SetText(FText::AsNumber(Amount));

	if(CurrencyType == XP)
	{
		RewardIcon->SetVisibility(ESlateVisibility::Hidden);
		XPText->SetVisibility(ESlateVisibility::Visible);
	}
}
