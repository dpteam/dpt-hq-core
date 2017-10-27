#include "zcommon.acs"
#library "hq_nbpr"

script 287 (int local0, int local1) // addr = 8, flags=0000
{
	int local2, local3;
	local2 = (GetActorPitch(0) - ((Random(1, 3) + 5) * local0));
	if ((local2 > -5780)) {
		SetActorPitch(0, local2);
	}
	local3 = (GetActorAngle(0) - ((Random(1, 2) + 4) * local1));
	SetActorangle(0, local3);
	Terminate;
}

script 288 (void) // addr = 69, flags=0000
{
	if ((CheckInventory("PowerStrength") == 1)) {
		ActivatorSound("powerup/berserk", 127);
		Delay(1050);
		TakeInventory("PowerStrength", 1);
	}
	Terminate;
}

script 289 (void) // addr = 95, flags=0000
{
	if ((GetActorProperty(APROP_Health, 0) < 100)) {
		SetActorProperty(APROP_Health, 0, 0);
	}
	Terminate;
}