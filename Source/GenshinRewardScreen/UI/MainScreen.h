// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Components/HorizontalBox.h"
#include "Components/ListView.h"
#include "GenshinRewardScreen/DataModel/QuestModel.h"
#include "Quests/QuestEntryItem.h"
#include "MainScreen.generated.h"

class UCurrencyView;

/**
 * 
 */
UCLASS()
class GENSHINREWARDSCREEN_API UMainScreen : public UCommonActivatableWidget
{
	GENERATED_BODY()

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UHorizontalBox> CurrencyHorizontalLayout = nullptr;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UListView> QuestListView = nullptr;

	UPROPERTY()
	TArray<UCurrencyView*> CurrencyViews;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UDataTable> QuestDataTable = nullptr;

	UPROPERTY()
	TArray<FQuest> QuestRows;

	UPROPERTY()
	TArray<UQuestEntryItem*> QuestDataObjects;

	UPROPERTY(EditDefaultsOnly)
	int CrystalRewardMax = 0;

	UPROPERTY(EditDefaultsOnly)
	int RubyRewardMax = 0;

	UPROPERTY(EditDefaultsOnly)
	int PrimogenRewardMax = 0;

	UPROPERTY(EditDefaultsOnly)
	int CrystalRewardMin = 0;

	UPROPERTY(EditDefaultsOnly)
	int RubyRewardMin = 0;

	UPROPERTY(EditDefaultsOnly)
	int PrimogemRewardMin = 0;
	
	UPROPERTY(EditDefaultsOnly)
	int ExperienceRewardMax = 0;

	UPROPERTY(EditDefaultsOnly)
	int ExperienceRewardMin = 0;

	UPROPERTY(EditDefaultsOnly)
	int MaxSubTaskAmount = 0;
	
	void GenerateQuestData();
	void DisplayQuests();
	static void AllocateCurrencyAmount(FReward& Reward, const int MaxAmount, const int MinAmount);

protected:
	virtual void NativeOnActivated() override;
	virtual UWidget* NativeGetDesiredFocusTarget() const override;
};
