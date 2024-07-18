// Fill out your copyright notice in the Description page of Project Settings.


#include "MainScreen.h"

#include "Currency/CurrencyView.h"

void UMainScreen::NativeConstruct()
{
	Super::NativeConstruct();

	// Get all CurrencyViews
	for (uint8 i = 0; i < CurrencyHorizontalLayout->GetAllChildren().Num(); i++)
	{
		if (UCurrencyView* CurrencyView = Cast<UCurrencyView>(CurrencyHorizontalLayout->GetAllChildren()[i]))
		{
			CurrencyViews.Emplace(CurrencyView);
			CurrencyView->InitCurrencyView();
		}
		else
		{
			UE_LOG(LogTemp, Error,
			       TEXT("Casting of Currency UWidget Type failed, widget will not be added to CurrencyViews array"));
		}
	}
}
