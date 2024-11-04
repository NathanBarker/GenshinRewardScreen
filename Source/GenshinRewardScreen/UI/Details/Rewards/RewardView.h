// Nathan Barker GenshinRewardScreen Personal Training Project. 

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "GenshinRewardScreen/GameData/CurrencyModel.h"
#include "RewardView.generated.h"

class UTextBlock;
class UCommonLazyImage;

/**
 * 
 */
UCLASS(Abstract)
class GENSHINREWARDSCREEN_API URewardView : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:

	void InitialiseReward(const ECurrency& CurrencyType, const int32& Amount);

private:

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UTextBlock> RewardAmount = nullptr;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UCommonLazyImage> RewardIcon = nullptr;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UCommonLazyImage> RewardBackground = nullptr;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UTextBlock> XPText = nullptr;
	
	// PrimoGen = 0, Ruby = 1, Crystal = 2
	UPROPERTY(EditDefaultsOnly)
	TArray<TSoftObjectPtr<UTexture2D>> RewardBackgrounds;

	UPROPERTY(EditDefaultsOnly)
	TArray<TSoftObjectPtr<UTexture2D>> RewardIcons;

	TSoftObjectPtr<UTexture2D> BackgroundTexture = nullptr;
	TSoftObjectPtr<UTexture2D> IconTexture = nullptr;
};
