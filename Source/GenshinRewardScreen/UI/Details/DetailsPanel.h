// Nathan Barker GenshinRewardScreen Personal Training Project. 

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Components/HorizontalBox.h"
#include "Components/ListView.h"
#include "Components/TextBlock.h"
#include "GenshinRewardScreen/Payloads/UIMessagePayloads.h"
#include "GenshinRewardScreen/UI/Quests/QuestProgressionView.h"
#include "Rewards/RewardView.h"
#include "DetailsPanel.generated.h"

/**
 * 
 */
UCLASS()
class GENSHINREWARDSCREEN_API UDetailsPanel : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:

	void InitialiseDetailsPanel(const FDetailsPanelMessage& InMessage) const;

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
	TSubclassOf<URewardView> RewardTemplate;
};
