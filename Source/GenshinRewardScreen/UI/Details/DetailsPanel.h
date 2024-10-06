// Nathan Barker GenshinRewardScreen Personal Training Project. 

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Components/ListView.h"
#include "Components/TextBlock.h"
#include "GenshinRewardScreen/GameplayMessages/GameplayMessages.h"
#include "GenshinRewardScreen/UI/Quests/QuestProgressionView.h"
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

private:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UTextBlock> QuestTitle = nullptr;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UQuestProgressionView> QuestProgression = nullptr;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UTextBlock> QuestDescription = nullptr;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UListView> ObjectivesListView = nullptr;
};
