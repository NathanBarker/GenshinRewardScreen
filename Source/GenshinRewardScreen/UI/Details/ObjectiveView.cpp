// Nathan Barker GenshinRewardScreen Personal Training Project. 


#include "ObjectiveView.h"
#include "ObjectiveItem.h"

void UObjectiveView::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	IUserObjectListEntry::NativeOnListItemObjectSet(ListItemObject);
	UObjectiveItem* Item = Cast<UObjectiveItem>(ListItemObject);
	UpdateObjectiveText(Item->ObjectiveText);
}

void UObjectiveView::NativeOnDeselected(bool bBroadcast)
{
	Super::NativeOnDeselected(bBroadcast);
}

void UObjectiveView::NativeOnSelected(bool bBroadcast)
{
	Super::NativeOnSelected(bBroadcast);
}

void UObjectiveView::UpdateObjectiveText(const FString& Objective) const
{
	ObjectiveText->SetText(FText::FromString(Objective));
}
