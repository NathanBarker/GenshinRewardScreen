// Nathan Barker GenshinRewardScreen Personal Training Project. 

#pragma once

#include "CoreMinimal.h"
#include "CommonUI/Public/Widgets/CommonActivatableWidgetContainer.h"
#include "CommonUserWidget.h"
#include "Details/DetailsPanel.h"
#include "MainScreen.h"
#include "GenshinRewardScreen/GameplayMessages/GameplayMessages.h"
#include "GameFramework/GameplayMessageSubsystem.h"
#include "Input/CommonUIInputTypes.h"

#include "BaseScreen.generated.h"

/**
 * 
 */
UCLASS()
class GENSHINREWARDSCREEN_API UBaseScreen : public UCommonUserWidget
{
	GENERATED_BODY()

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UCommonActivatableWidgetStack> MainMenuStack = nullptr;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UMainScreen> MainScreenTemplate;
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UDetailsPanel> DetailsPanelTemplate;

	UPROPERTY()
	TObjectPtr<UGameplayMessageSubsystem> MessageSubsystem = nullptr;

	virtual void NativeConstruct() override;
	void ActivateDetailsPanel(FGameplayTag InChannel, const FDetailsPanelMessage& InMessage);
};
