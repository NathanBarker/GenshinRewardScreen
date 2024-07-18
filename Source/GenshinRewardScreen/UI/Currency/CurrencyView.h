// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "CurrencyView.generated.h"

/**
 * 
 */
UCLASS()
class GENSHINREWARDSCREEN_API UCurrencyView : public UCommonUserWidget
{
	GENERATED_BODY()

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UTextBlock> CurrencyText = nullptr;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UImage> CurrencyIcon = nullptr;
	
	UPROPERTY(EditDefaultsOnly)
	TArray<UTexture2D*> CurrencyTextures;

	UPROPERTY(EditInstanceOnly)
	UTexture2D* IconTexture;

public:
	void NativePreConstruct() override;
	void InitCurrencyView() const;
	void SetCurrencyIconBrush(UTexture2D* currencyIcon) const;
	void SetCurrencyText(const uint8 currencyAmount) const;
};
