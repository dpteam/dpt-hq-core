#include "zcommon.acs"
#library "hq_buhlo"

script 556 (void)
{
	While(checkinventory("DrunkLevel")>1 && checkinventory("DrunkLevel2")>1)
	{
		Delay((35*60)*5);
		TakeInventory("DrunkLevel",1);
		TakeInventory("DrunkLevel2",1);
	}
}