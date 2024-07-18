// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "QuestEntryItem.generated.h"

/**
 * 
 */
UCLASS()
class GENSHINREWARDSCREEN_API UQuestEntryItem : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString QuestName;

	UPROPERTY()
	FString QuestDescription;
};
