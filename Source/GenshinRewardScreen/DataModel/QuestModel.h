#pragma once

#include "QuestModel.generated.h"

USTRUCT()
struct FQuest : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY()
	FString Name;

	UPROPERTY()
	FString Description;

	UPROPERTY()
	TArray<FString> Objectives;
};
