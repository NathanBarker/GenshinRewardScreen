// Nathan Barker GenshinRewardScreen Personal Training Project. 

#pragma once

#include "Blueprint/IUserObjectListEntry.h"
#include "CommonButtonBase.h"
#include "Components/HorizontalBox.h"
#include "Components/TextBlock.h"
#include "CoreMinimal.h"
#include "GameFramework/GameplayMessageSubsystem.h"
#include "NativeGameplayTags.h"
#include "QuestEntryItem.h"
#include "QuestProgressionView.h"
#include "QuestRewardView.h"
#include "Components/WidgetSwitcher.h"

#include "QuestListView.generated.h"

GENSHINREWARDSCREEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(UI_Message_On_Quest_Selection_Changed);
GENSHINREWARDSCREEN_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(UI_Message_On_Quest_Claim);

/**
 * 
 */
UCLASS()
class GENSHINREWARDSCREEN_API UQuestListView : public UCommonButtonBase, public IUserObjectListEntry
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditDefaultsOnly)
	FDataTableRowHandle DetailsInput;
	
	FUIActionBindingHandle DetailsInputHandle;

	UPROPERTY(EditDefaultsOnly)
	FDataTableRowHandle ClaimInput;

	FUIActionBindingHandle ClaimInputHandle;
	
	UPROPERTY()
	TObjectPtr<UQuestEntryItem> QuestEntryItem = nullptr;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UTextBlock> QuestTitle = nullptr;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UImage> CompletedBg = nullptr;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UQuestProgressionView> WBP_QuestProgression = nullptr;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UHorizontalBox> RewardsContainer;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UWidgetSwitcher> ProgressSwitcher = nullptr;;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UQuestRewardView> QuestRewardTemplate;

	// PrimoGen = 0, Ruby = 1, Crystal = 2
	UPROPERTY(EditDefaultsOnly)
	TArray<UTexture2D*> RewardBackgrounds;

	UPROPERTY(EditDefaultsOnly)
	TArray<UTexture2D*> RewardIcons;

	UPROPERTY()
	TObjectPtr<UGameplayMessageSubsystem> MessageSubsystem = nullptr;
	
	// IUserObjectListEntry
	virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;
	// IUserObjectListEntry
	
	virtual void NativeConstruct() override;
	virtual void NativeOnSelected(bool bBroadcast) override;
	virtual void NativeOnClicked() override;
	virtual void NativeOnDeselected(bool bBroadcast) override;

	void SetRewardsWidgets(UQuestEntryItem* Item);
	void ClaimRewardCallback();
};
