#pragma once

#include "GenshinRewardScreen/DataModel/CurrencyModel.h"
#include "QuestRewards.generated.h"

USTRUCT()
struct FReward
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	TEnumAsByte<ECurrency> CurrencyType = None;

	UPROPERTY()
	int Amount = 0;
};
