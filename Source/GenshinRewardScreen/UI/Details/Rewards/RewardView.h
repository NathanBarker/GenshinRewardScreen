// Nathan Barker GenshinRewardScreen Personal Training Project. 

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "GenshinRewardScreen/GameData/CurrencyModel.h"
#include "RewardView.generated.h"

/**
 * 
 */
UCLASS()
class GENSHINREWARDSCREEN_API URewardView : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:

	void InitialiseReward(const ECurrency& CurrencyType, const int32& Amount);

private:

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UTextBlock> RewardAmount = nullptr;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UImage> RewardIcon = nullptr;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UImage> RewardBackground = nullptr;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UTextBlock> XPText = nullptr;
	
	// PrimoGen = 0, Ruby = 1, Crystal = 2
	UPROPERTY(EditDefaultsOnly)
	TArray<UTexture2D*> RewardBackgrounds;

	UPROPERTY(EditDefaultsOnly)
	TArray<UTexture2D*> RewardIcons;
};
