// Nathan Barker GenshinRewardScreen Personal Training Project. 

#include "GenshinUiSettings.h"
#include "Engine/DataTable.h"


const UGenshinUiSettings* UGenshinUiSettings::Get()
{
	return GetDefault<UGenshinUiSettings>();
}

TObjectPtr<UDataTable> UGenshinUiSettings::GetQuestDataTable()
{
	TObjectPtr<UDataTable> Table = Get()->QuestDataTable.Get();
	if (!IsValid(Table))
	{
		Table = Get()->QuestDataTable.LoadSynchronous();
	}
	return Table;
}
