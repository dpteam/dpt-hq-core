#include "zcommon.acs"
#library "hq_axe"

Script "Axe charge" (void)
{
	int axe_charge = CheckInventory("AxeCharge");
	TakeInventory("AxeCharge", 0x7FFFFFFF); // [Blue Shadow] Clear the charge counter
	SetResultValue(axe_charge);
}