// Nathan Barker GenshinRewardScreen Personal Training Project. 

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"

#include "QuestProgressionView.generated.h"

class UTextBlock;
class UProgressBar;

/**
 * 
 */
UCLASS()
class GENSHINREWARDSCREEN_API UQuestProgressionView : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	
	void SetProgression(const float& Progression) const;

protected:
	
	virtual void NativePreConstruct() override;

private:

	UPROPERTY(meta=(BindWidget))
    TObjectPtr<UProgressBar> ProgressBar = nullptr;
    
    UPROPERTY(meta=(BindWidget))
    TObjectPtr<UTextBlock> QuestProgression = nullptr;
};
