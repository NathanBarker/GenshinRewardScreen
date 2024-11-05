// Nathan Barker GenshinRewardScreen Personal Training Project. 


#include "BaseScreen.h"

#include "MainScreen.h"
#include "Details/DetailsPanel.h"
#include "Quests/QuestListView.h"
#include "CommonUI/Public/Widgets/CommonActivatableWidgetContainer.h"

void UBaseScreen::NativeConstruct()
{
	Super::NativeConstruct();
	
	UGameplayMessageSubsystem& MessageSubsystem = UGameplayMessageSubsystem::Get(this);
	MessageSubsystem.RegisterListener(
		UI_Message_On_Quest_Selection_Changed, this, &UBaseScreen::ActivateDetailsPanel);
	
	if (IsValid(MainScreenTemplate))
	{
		MainMenuStack->AddWidget(MainScreenTemplate);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Main Screen failed to get pushed onto the stack because the template was null."));
	}
}

void UBaseScreen::ActivateDetailsPanel(FGameplayTag InChannel, const FDetailsPanelMessage& InMessage)
{
	UDetailsPanel* DetailsPanel = Cast<UDetailsPanel>(MainMenuStack->AddWidget(DetailsPanelTemplate));
	DetailsPanel->InitialiseDetailsPanel(InMessage);
}
