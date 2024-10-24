// Nathan Barker GenshinRewardScreen Personal Training Project. 

#include "MainScreen.h"

#include "Currency/CurrencyView.h"
#include "GenshinRewardScreen/HelperClasses/QuestObjectiveData.h"
#include "Quests/QuestListView.h"

void UMainScreen::NativeConstruct()
{
	Super::NativeConstruct();

	if (!IsValid(PlayerInventory))
	{
		PlayerInventory = NewObject<UInventory>();
	}

	if (QuestDataObjects.IsEmpty())
	{
		GenerateQuestData();
	}

	MessageSubsystem = UGameplayMessageSubsystem::Get(this);
	MessageSubsystem->RegisterListener(
		UI_Message_On_Quest_Claim, this, &UMainScreen::ClaimQuest);
}

void UMainScreen::NativeOnActivated()
{
	Super::NativeOnActivated();

	GetDesiredFocusTarget()->SetFocus();

	for (int i = 0; i < CurrencyHorizontalLayout->GetAllChildren().Num(); i++)
	{
		if (UCurrencyView* CurrencyView = Cast<UCurrencyView>(CurrencyHorizontalLayout->GetAllChildren()[i]))
		{
			CurrencyViews.Emplace(CurrencyView);

			if (IsValid(PlayerInventory))
			{
				CurrencyView->SetCurrencyText(PlayerInventory->GetCurrencyAmount(i));
			}
		}
		else
		{
			UE_LOG(LogTemp, Error,
			       TEXT("Casting of Currency UWidget Type failed, widget will not be added to CurrencyViews array"));
			return;
		}
	}
}

void UMainScreen::GenerateQuestData()
{
	TArray<FName> RowNames = QuestDataTable->GetRowNames();
	for (const FName QuestData : RowNames)
	{
		FQuest QuestEntryObject = *QuestDataTable->FindRow<FQuest>(QuestData, "");
		QuestRows.Emplace(QuestEntryObject);
	}
	InitialiseQuests();
}

void UMainScreen::InitialiseQuests()
{
	QuestDataObjects = QuestObjectiveData::CreateQuests(QuestRows, MaxSubTaskAmount, ExperienceRewardMax,
	                                                    ExperienceRewardMin, MaxCurrencyRewards, MinCurrencyRewards);

	QuestDataObjects.Sort();
	QuestList->SetListItems(QuestDataObjects);
}

void UMainScreen::ClaimQuest(FGameplayTag InChannel, const FClaimMessage& InMessage)
{
	UQuestEntryItem* QuestEntryItem = Cast<UQuestEntryItem>(InMessage.QuestItem);
	int32 IndexOfQuestToClaim = QuestDataObjects.Find(QuestEntryItem);

	QuestDataObjects[IndexOfQuestToClaim]->isCompleted = true;

	for (const FReward Reward : QuestDataObjects[IndexOfQuestToClaim]->Rewards)
	{
		PlayerInventory->AddCurrencyAmount(Reward.CurrencyType, Reward.CurrencyAmount);
	}

	UpdateCurrencyViews(QuestEntryItem->Rewards);
}

void UMainScreen::UpdateCurrencyViews(const TArray<FReward>& Rewards)
{
	for (int i = 0; i < Rewards.Num(); i++)
	{
		if (IsValid(PlayerInventory))
		{
			CurrencyViews[Rewards[i].CurrencyType]->SetCurrencyText(
				PlayerInventory->GetCurrencyAmount(Rewards[i].CurrencyType));
		}
		else
		{
			UE_LOG(LogTemp, Error,
			       TEXT("Unable to apply %i to CurrencyView "), Rewards[i].CurrencyType.GetValue());
			return;
		}
	}
}

UWidget* UMainScreen::NativeGetDesiredFocusTarget() const
{
	QuestList->SetFocus();
	return QuestList;
}
