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
	TObjectPtr<UListView> QuestList = nullptr;

	UPROPERTY()
	TArray<UCurrencyView*> CurrencyViews;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UDataTable> QuestDataTable = nullptr;

	UPROPERTY()
	TArray<FQuest> QuestRows;

	UPROPERTY()
	TArray<UQuestEntryItem*> QuestDataObjects;

	//
	// PrimoGen = 0, Ruby = 1, Crystal = 2
	// MAX AMOUNTS
	// Primogen = 50, Ruby = 99, Crystal = 10, 
	UPROPERTY(EditDefaultsOnly)
	TArray<int> MaxCurrencyRewards;

	// MIN AMOUNTS
	// Primogen = 1, Ruby = 10, Crystal = 1
	UPROPERTY(EditDefaultsOnly)
	TArray<int> MinCurrencyRewards;
	//

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
