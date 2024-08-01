// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "QuestProgressionView.generated.h"

/**
 * 
 */
UCLASS()
class GENSHINREWARDSCREEN_API UQuestProgressionView : public UCommonUserWidget
{
	GENERATED_BODY()

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UProgressBar> ProgressBar = nullptr;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UTextBlock> QuestProgression = nullptr;

	virtual void NativePreConstruct() override;

public:
	void SetProgression(const int& Progression) const;
};
