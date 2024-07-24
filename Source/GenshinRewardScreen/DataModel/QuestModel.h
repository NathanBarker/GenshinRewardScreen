#pragma once

#include "QuestModel.generated.h"

USTRUCT()
struct FQuest : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditDefaultsOnly)
	FString Name;

	UPROPERTY(EditDefaultsOnly)
	FString Description;

	UPROPERTY(EditDefaultsOnly)
	TArray<FString> Objectives;
};
