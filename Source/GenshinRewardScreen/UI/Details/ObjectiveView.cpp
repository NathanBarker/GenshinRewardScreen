// Nathan Barker GenshinRewardScreen Personal Training Project. 

#include "ObjectiveView.h"

#include "Components/TextBlock.h"
#include "ObjectiveItem.h"

void UObjectiveView::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	IUserObjectListEntry::NativeOnListItemObjectSet(ListItemObject);
	const UObjectiveItem* Item = Cast<UObjectiveItem>(ListItemObject);
	UpdateObjectiveText(Item->ObjectiveText);
}

void UObjectiveView::UpdateObjectiveText(const FString& Objective) const
{
	ObjectiveText->SetText(FText::FromString(Objective));
}
