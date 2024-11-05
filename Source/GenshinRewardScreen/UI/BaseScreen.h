// Nathan Barker GenshinRewardScreen Personal Training Project. 

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "GameFramework/GameplayMessageSubsystem.h"

#include "BaseScreen.generated.h"

struct FDetailsPanelMessage;
class UDetailsPanel;
class UMainScreen;
class UCommonActivatableWidgetStack;
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
	
	void ActivateDetailsPanel(FGameplayTag InChannel, const FDetailsPanelMessage& InMessage);
};
