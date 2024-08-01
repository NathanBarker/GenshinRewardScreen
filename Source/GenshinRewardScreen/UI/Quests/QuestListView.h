// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "QuestEntryItem.h"
#include "QuestProgressionView.h"
#include "QuestRewardView.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "Components/HorizontalBox.h"
#include "Components/Image.h"
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

	void NativeConstruct() override;

	void SetRewardsWidgets(const UQuestEntryItem* Item);
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
};
