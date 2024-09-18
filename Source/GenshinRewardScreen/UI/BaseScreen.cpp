// Nathan Barker GenshinRewardScreen Personal Training Project. 


#include "BaseScreen.h"

#include "GenshinRewardScreen/GameplayMessages/GameplayMessages.h"
#include "Input/CommonUIInputTypes.h"

void UBaseScreen::NativeConstruct()
{
	Super::NativeConstruct();

	if (IsValid(MainScreenTemplate))
	{
		UMainScreen* MainScreen = Cast<UMainScreen>(MainMenuStack->AddWidget(MainScreenTemplate));
		MainScreen->ActivateWidget();
		MessageSubsystem = UGameplayMessageSubsystem::Get(this);
		FGameplayMessageListenerHandle ListenerHandle = MessageSubsystem->RegisterListener(UI_Message_OpenPanel, this, &UBaseScreen::ActivateDetailsPanel);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Main Screen failed to get pushed onto the stack"));
	}
}

void UBaseScreen::ActivateDetailsPanel(FGameplayTag InChannel, const FDetailsPanelMessage& InMessage)
{
	MainMenuStack->AddWidget(DetailsPanelTemplate);
}
