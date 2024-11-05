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

public:
	void InitializeReward(const TSoftObjectPtr<UTexture2D>& Background,
	                      const TSoftObjectPtr<UTexture2D>& Icon,
	                      const int32& Amount);

private:

	UPROPERTY(meta=(BindWidget))
    TObjectPtr<UCommonLazyImage> RewardIcon = nullptr;
    
    UPROPERTY(meta=(BindWidget))
    TObjectPtr<UCommonLazyImage> RewardBackground = nullptr;
    
    UPROPERTY(meta=(BindWidget))
    TObjectPtr<UTextBlock> RewardAmount = nullptr;
};
