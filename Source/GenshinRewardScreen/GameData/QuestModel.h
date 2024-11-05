// Nathan Barker GenshinRewardScreen Personal Training Project. 

#pragma once

#include "QuestModel.generated.h"

USTRUCT()
struct FQuest : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FString Name = "";

	UPROPERTY(EditAnywhere)
	FString Description = "";

	UPROPERTY(EditAnywhere)
	TArray<FString> Objectives = {};
};
