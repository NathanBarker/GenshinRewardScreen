#pragma once

#include "GenshinRewardScreen/DataModel/CurrencyModel.h"
#include "QuestRewards.generated.h"

USTRUCT()
struct FReward
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	TEnumAsByte<ECurrency> CurrencyType = Crystal;

	UPROPERTY()
	int CurrencyAmount = 0;

	FReward() = default;
	FReward(const ECurrency& Type, const int& MaxCurrencyAmount, const int& MinCurrencyAmount);

	bool operator< (const FReward& Other) const
	{
		return Other.CurrencyType < CurrencyType;
	}
};
