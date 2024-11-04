// Nathan Barker GenshinRewardScreen Personal Training Project. 

#pragma once

#include "CoreMinimal.h"
#include "CommonUI/Public/Widgets/CommonActivatableWidgetContainer.h"
#include "CommonUserWidget.h"
#include "Details/DetailsPanel.h"
#include "MainScreen.h"
#include "GenshinRewardScreen/Payloads/UIMessagePayloads.h"
#include "GameFramework/GameplayMessageSubsystem.h"
#include "Input/CommonUIInputTypes.h"

#include "BaseScreen.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class GENSHINREWARDSCREEN_API UBaseScreen : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	
	virtual void NativeConstruct() override;

private:
	
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UCommonActivatableWidgetStack> MainMenuStack = nullptr;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UMainScreen> MainScreenTemplate = nullptr;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UDetailsPanel> DetailsPanelTemplate = nullptr;

	UPROPERTY()
	TObjectPtr<UGameplayMessageSubsystem> MessageSubsystem = nullptr;

	void ActivateDetailsPanel(FGameplayTag InChannel, const FDetailsPanelMessage& InMessage);
};
