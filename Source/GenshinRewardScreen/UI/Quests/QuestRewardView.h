// Nathan Barker GenshinRewardScreen Personal Training Project. 

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "QuestRewardView.generated.h"

class UTextBlock;
class UCommonLazyImage;

/**
 * 
 */
UCLASS(Abstract)
class GENSHINREWARDSCREEN_API UQuestRewardView : public UCommonUserWidget
{
	GENERATED_BODY()

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UCommonLazyImage> RewardIcon = nullptr;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UCommonLazyImage> RewardBackground = nullptr;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UTextBlock> RewardAmount = nullptr;

public:
	void InitializeReward(UTexture2D* Background, UTexture2D* RewardIcon, const int32& Amount) const;
};
