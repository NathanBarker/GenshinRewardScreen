// Nathan Barker GenshinRewardScreen Personal Training Project. 

#include "CurrencyView.h"

void UCurrencyView::NativePreConstruct()
{
	Super::NativePreConstruct();
	SetCurrencyIconBrush(IconTexture);
}

void UCurrencyView::SetCurrencyIconBrush(UTexture2D* Icon)
{
	CurrencyIcon->SetBrushFromTexture(Icon);
}

void UCurrencyView::SetCurrencyText(const int& CurrencyAmount)
{
	const FString AmountText = FString::FromInt(CurrencyAmount);
	CurrencyText->SetText(FText::FromString(AmountText));
}