// Nathan Barker GenshinRewardScreen Personal Training Project. 

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
	virtual void NativePreConstruct() override;
	void SetCurrencyIconBrush(UTexture2D* Icon);
	void SetCurrencyText(const int32& CurrencyAmount);
};
