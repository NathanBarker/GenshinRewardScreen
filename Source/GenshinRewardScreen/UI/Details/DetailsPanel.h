// Nathan Barker GenshinRewardScreen Personal Training Project. 

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "GenshinRewardScreen/Payloads/UIMessagePayloads.h"
#include "GenshinRewardScreen/UI/Quests/QuestProgressionView.h"
#include "Rewards/RewardView.h"
#include "DetailsPanel.generated.h"

class UTextBlock;
class UHorizontalBox;
class UListView;

/**
 * 
 */
UCLASS(Abstract)
class GENSHINREWARDSCREEN_API UDetailsPanel : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	void InitialiseDetailsPanel(const FDetailsPanelMessage& InMessage);

protected:
	virtual void NativeOnDeactivated() override;

private:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UTextBlock> QuestTitle = nullptr;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UQuestProgressionView> QuestProgression = nullptr;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UTextBlock> QuestDescription = nullptr;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UListView> ObjectivesListView = nullptr;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<URewardView> XPReward = nullptr;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UHorizontalBox> RewardsContainer = nullptr;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<URewardView> RewardTemplate = nullptr;

	UPROPERTY(EditDefaultsOnly)
	FMargin RewardViewPadding = {0, 0, 50, 0};

	void DisplayRewards(const int32& XPAmount, const TArray<FReward>& Rewards);
	void ConfigureReward(URewardView& RewardView, const ECurrency& CurrencyType, const int32 CurrencyAmount);
};
