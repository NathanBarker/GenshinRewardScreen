// Nathan Barker GenshinRewardScreen Personal Training Project. 


#include "RewardView.h"

void URewardView::InitialiseReward(const ECurrency& CurrencyType, const int32& Amount)
{
	UTexture2D* BackgroundTexture = nullptr;
	UTexture2D* IconTexture = nullptr;

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
	if (!BackgroundTexture || !IconTexture)
	{
		UE_LOG(LogTemp, Error, TEXT("Reward View failed to get created"));
		return;
	}

	RewardBackground->SetBrushFromTexture(BackgroundTexture);
	RewardIcon->SetBrushFromTexture(IconTexture);
	RewardAmount->SetText(FText::FromString(FString::FromInt(Amount)));

	if(CurrencyType == XP)
	{
		RewardIcon->SetVisibility(ESlateVisibility::Hidden);
		XPText->SetVisibility(ESlateVisibility::Visible);
	}
}
