#include "QuestRewards.h"

FReward::FReward(const ECurrency& Type, const int& MaxCurrencyAmount, const int& MinCurrencyAmount): CurrencyType(Type)
{
	CurrencyType = Type;
	CurrencyAmount = rand() % MaxCurrencyAmount + MinCurrencyAmount;
}
