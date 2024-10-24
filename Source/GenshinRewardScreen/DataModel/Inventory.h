// Nathan Barker GenshinRewardScreen Personal Training Project.

#pragma once

#include "Inventory.generated.h"

UCLASS()
class UInventory : public UObject
{
	GENERATED_BODY()
	
public:
	void AddCurrencyAmount(const int& Currency, const int& NewAmount)
	{
		CurrencyList[Currency] =+ NewAmount;
	};

	int GetCurrencyAmount(const int& Currency)
	{
		return CurrencyList[Currency];
	};

private:
	int PrimogenAmount = 0;
	int RubyAmount = 0;
	int CrystalAmount = 0;

	UPROPERTY()
	TArray<int> CurrencyList = {PrimogenAmount, RubyAmount, CrystalAmount};
};
