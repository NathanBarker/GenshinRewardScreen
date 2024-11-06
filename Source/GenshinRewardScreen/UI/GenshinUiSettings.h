// Nathan Barker GenshinRewardScreen Personal Training Project. 

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "GenshinUiSettings.generated.h"

UCLASS(Config = Game, DefaultConfig)
class GENSHINREWARDSCREEN_API UGenshinUiSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	static const UGenshinUiSettings* Get();
	
	static TObjectPtr<UDataTable> GetQuestDataTable();

private:
	UPROPERTY(Config, EditAnywhere)
	TSoftObjectPtr<UDataTable> QuestDataTable = nullptr;
};
