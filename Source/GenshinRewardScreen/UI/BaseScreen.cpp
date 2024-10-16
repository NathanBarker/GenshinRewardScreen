// Nathan Barker GenshinRewardScreen Personal Training Project. 


#include "BaseScreen.h"
#include "Quests/QuestListView.h"

void UBaseScreen::NativeConstruct()
{
	Super::NativeConstruct();

	if (IsValid(MainScreenTemplate))
	{
		UMainScreen* MainScreen = Cast<UMainScreen>(MainMenuStack->AddWidget(MainScreenTemplate));
		MainScreen->ActivateWidget();
		MessageSubsystem = UGameplayMessageSubsystem::Get(this);
		MessageSubsystem->RegisterListener(
			UI_Message_On_Quest_Selection_Changed, this, &UBaseScreen::ActivateDetailsPanel);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Main Screen failed to get pushed onto the stack"));
	}
}

void UBaseScreen::ActivateDetailsPanel(FGameplayTag InChannel, const FDetailsPanelMessage& InMessage)
{
	UDetailsPanel* DetailsPanel = Cast<UDetailsPanel>(MainMenuStack->AddWidget(DetailsPanelTemplate));
	DetailsPanel->InitialiseDetailsPanel(InMessage);
}
