// Nathan Barker GenshinRewardScreen Personal Training Project.

#pragma once

#include "GenshinRewardScreen/GameData/CurrencyModel.h"
#include "QuestRewards.generated.h"

USTRUCT()
struct FReward
{
	GENERATED_BODY()
	
	TEnumAsByte<ECurrency> CurrencyType = Crystal;
	
	int CurrencyAmount = 0;

	FReward() = default;
	FReward(const ECurrency& Type, const int32& MaxCurrencyAmount, const int32& MinCurrencyAmount);

	bool operator< (const FReward& Other) const
	{
		return Other.CurrencyType < CurrencyType;
	}
};
