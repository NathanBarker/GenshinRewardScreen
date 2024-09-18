// Nathan Barker GenshinRewardScreen Personal Training Project. 

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "QuestEntryItem.h"
#include "QuestProgressionView.h"
#include "QuestRewardView.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "Components/HorizontalBox.h"
#include "Components/TextBlock.h"
#include "QuestListView.generated.h"

/**
 * 
 */
UCLASS()
class GENSHINREWARDSCREEN_API UQuestListView : public UCommonButtonBase, public IUserObjectListEntry
{
	GENERATED_BODY()

protected:
	// IUserObjectListEntry
	virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;
	// IUserObjectListEntry

	virtual void NativeConstruct() override;
	virtual void NativeOnSelected(bool bBroadcast) override;
	virtual void NativeOnDeselected(bool bBroadcast) override;

	void SetRewardsWidgets(UQuestEntryItem* Item);

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UTextBlock> QuestTitle = nullptr;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UQuestProgressionView> WBP_QuestProgression = nullptr;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UHorizontalBox> RewardsContainer;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UQuestRewardView> QuestRewardTemplate;

	// PrimoGen = 0, Ruby = 1, Crystal = 2
	UPROPERTY(EditDefaultsOnly)
	TArray<UTexture2D*> RewardBackgrounds;

	UPROPERTY(EditDefaultsOnly)
	TArray<UTexture2D*> RewardIcons;

	FVector2D SelectedSize = {700.0f, 100.0f};
	FVector2D DefaultSize = {600.0f, 100.0f};

	UPROPERTY(Transient, meta=(BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> Selected;

	UPROPERTY(Transient, meta=(BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> Default;
};
