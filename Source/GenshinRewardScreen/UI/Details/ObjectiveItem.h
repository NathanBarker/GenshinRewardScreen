// Nathan Barker GenshinRewardScreen Personal Training Project. 

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ObjectiveItem.generated.h"

/**
 * 
 */
UCLASS()
class GENSHINREWARDSCREEN_API UObjectiveItem : public UObject
{
	GENERATED_BODY()

public:
	UObjectiveItem() = default;
	
	FString ObjectiveText = "";
};
