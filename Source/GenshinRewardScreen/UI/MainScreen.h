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

	// PrimoGen = 0, Ruby = 1, Crystal = 2
	// Max Amounts
	// Crystal = 10, Ruby = 99, Primogen = 50
	UPROPERTY(EditDefaultsOnly)
	TArray<int> MaxCurrencyRewards = {50, 99, 10}; 

	// PrimoGen = 0, Ruby = 1, Crystal = 2
	// Min Amounts
	// Crystal = 10, Ruby = 99, Primogen = 50
	UPROPERTY(EditDefaultsOnly)
	TArray<int> MinCurrencyRewards = {1, 10, 1}; 
	
	UPROPERTY(EditDefaultsOnly)
	int ExperienceRewardMax = 0;

	UPROPERTY(EditDefaultsOnly)
	int ExperienceRewardMin = 0;

	UPROPERTY(EditDefaultsOnly)
	int MaxSubTaskAmount = 0;
	
	void GenerateQuestData();
	void InitialiseQuests();

protected:
	virtual void NativeOnActivated() override;
	virtual UWidget* NativeGetDesiredFocusTarget() const override;
};
