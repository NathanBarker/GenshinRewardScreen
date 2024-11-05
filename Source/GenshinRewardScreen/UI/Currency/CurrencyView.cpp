// Nathan Barker GenshinRewardScreen Personal Training Project. 

#include "CurrencyView.h"

#include "Components/TextBlock.h"
#include "CommonUI/Public/CommonLazyImage.h"

void UCurrencyView::NativePreConstruct()
{
	Super::NativePreConstruct();
	SetCurrencyIconBrush(IconTexture);
}

void UCurrencyView::SetCurrencyIconBrush(UTexture2D* Icon)
{
	CurrencyIcon->SetBrushFromLazyTexture(Icon);
}

void UCurrencyView::SetCurrencyText(const int32& CurrencyAmount)
{
	CurrencyText->SetText(FText::AsNumber(CurrencyAmount));
}