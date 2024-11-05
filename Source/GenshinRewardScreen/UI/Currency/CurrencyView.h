// Nathan Barker GenshinRewardScreen Personal Training Project. 

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "CurrencyView.generated.h"

class UTextBlock;
class UCommonLazyImage;

/**
 * 
 */
UCLASS(Abstract)
class GENSHINREWARDSCREEN_API UCurrencyView : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	
	void SetCurrencyIconBrush(UTexture2D* Icon);
	void SetCurrencyText(const int32& CurrencyAmount);

protected:
	
	virtual void NativePreConstruct() override;

private:
	
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UTextBlock> CurrencyText = nullptr;

	UPROPERTY(meta=(BindWidget))
	TSoftObjectPtr<UCommonLazyImage> CurrencyIcon = nullptr;

	UPROPERTY(EditDefaultsOnly)
	TArray<UTexture2D*> CurrencyTextures;

	UPROPERTY(EditInstanceOnly)
	UTexture2D* IconTexture;
};
