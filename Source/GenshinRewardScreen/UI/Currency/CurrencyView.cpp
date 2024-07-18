// Fill out your copyright notice in the Description page of Project Settings.

#include "CurrencyView.h"

void UCurrencyView::NativePreConstruct()
{
	Super::NativePreConstruct();
	SetCurrencyIconBrush(IconTexture);
}

void UCurrencyView::InitCurrencyView() const
{
	SetCurrencyText(0);
}

void UCurrencyView::SetCurrencyIconBrush(UTexture2D* currencyIcon) const
{
	CurrencyIcon->SetBrushFromTexture(currencyIcon);
}

void UCurrencyView::SetCurrencyText(const uint8 currencyAmount) const
{
	FString currencyText = FString::FromInt(currencyAmount);
	CurrencyText->SetText(FText::FromString(currencyText));
}
