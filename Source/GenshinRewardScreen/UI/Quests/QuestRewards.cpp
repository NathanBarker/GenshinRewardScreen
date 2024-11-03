// Nathan Barker GenshinRewardScreen Personal Training Project. 

#include "QuestRewards.h"

FReward::FReward(const ECurrency& Type, const int32& MaxCurrencyAmount, const int32& MinCurrencyAmount): CurrencyType(Type)
{
	CurrencyType = Type;
	CurrencyAmount = rand() % MaxCurrencyAmount + MinCurrencyAmount;
}
