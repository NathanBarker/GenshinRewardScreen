// Nathan Barker GenshinRewardScreen Personal Training Project. 

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "QuestRewardView.generated.h"

/**
 * 
 */
UCLASS()
class GENSHINREWARDSCREEN_API UQuestRewardView : public UCommonUserWidget
{
	GENERATED_BODY()

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UImage> RewardIcon = nullptr;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UImage> RewardBackground = nullptr;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UTextBlock> RewardAmount = nullptr;

public:
	void InitializeReward(UTexture2D* Background, UTexture2D* RewardIcon, const int32& Amount) const;
};
