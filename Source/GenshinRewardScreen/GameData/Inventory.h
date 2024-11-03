// Nathan Barker GenshinRewardScreen Personal Training Project.

#pragma once

#include "Inventory.generated.h"

UCLASS()
class UInventory : public UObject
{
	GENERATED_BODY()

public:
	void AddCurrencyAmount(const int32& Currency, const int32& NewAmount)
	{
		if (CurrencyList.IsValidIndex(Currency)) CurrencyList[Currency] = +NewAmount;
	};

	int32 GetCurrencyAmount(const int32& Currency) const
	{
		if (CurrencyList.IsValidIndex(Currency)) return CurrencyList[Currency];
		return 0;
	};

private:
	int32 PrimogenAmount = 0;
	int32 RubyAmount = 0;
	int32 CrystalAmount = 0;

	UPROPERTY()
	TArray<int32> CurrencyList = {PrimogenAmount, RubyAmount, CrystalAmount};
};
