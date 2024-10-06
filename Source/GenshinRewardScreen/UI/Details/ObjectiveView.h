// Nathan Barker GenshinRewardScreen Personal Training Project. 

#pragma once

#include "Blueprint/IUserObjectListEntry.h"
#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "Components/TextBlock.h"
#include "ObjectiveView.generated.h"

/**
 * 
 */
UCLASS()
class GENSHINREWARDSCREEN_API UObjectiveView : public UCommonButtonBase, public IUserObjectListEntry
{
	GENERATED_BODY()
	
protected:
	// IUserObjectListEntry
	virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;
	// IUserObjectListEntry

	virtual void NativeOnDeselected(bool bBroadcast) override;
	virtual void NativeOnSelected(bool bBroadcast) override;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UTextBlock> ObjectiveText = nullptr;

private:
	void UpdateObjectiveText(const FString& ObjectiveText) const;
};
