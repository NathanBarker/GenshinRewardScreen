// Nathan Barker GenshinRewardScreen Personal Training Project. 

#pragma once

#include "Blueprint/IUserObjectListEntry.h"
#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "ObjectiveView.generated.h"

class UTextBlock;

/**
 * 
 */
UCLASS(Abstract)
class GENSHINREWARDSCREEN_API UObjectiveView : public UCommonButtonBase, public IUserObjectListEntry
{
	GENERATED_BODY()
	
protected:
	// IUserObjectListEntry
	virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;
	// IUserObjectListEntry

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UTextBlock> ObjectiveText = nullptr;

private:
	void UpdateObjectiveText(const FString& ObjectiveText);
};
