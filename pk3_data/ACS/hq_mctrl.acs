#include "zcommon.acs"
#library "hq_mctrl"

script 522 OPEN
{
	ConsoleCommand("compat_clientssendfullbuttoninfo 1");
}
//FORWARD
script 421 ENTER
{
	int buttons;
	while (TRUE)
	{
		buttons = GetPlayerInput(-1, INPUT_BUTTONS);
		if (buttons & BT_FORWARD)
		{
			GiveInventory("Accelerate", 1);
			//giveinventory("HealthBonus", GetActorProperty(0, APROP_HEALTH));
			delay(1);
		}
		delay(1);
		TakeInventory("Accelerate", 1);
	}
}
//BACKPEDAL
script 422 ENTER
{
	int buttons;
	while (TRUE)
	{
		buttons = GetPlayerInput(-1, INPUT_BUTTONS);
		if (buttons & BT_BACK)
		{
			GiveInventory("BackPedal", 1);
			delay(2);
		}
		delay(2);
		TakeInventory("BackPedal", 1);
	}
}
//LEFT
script 423 ENTER
{
	int buttons;
	while (TRUE)
	{
		buttons = GetPlayerInput(-1, INPUT_BUTTONS);
		if (buttons & BT_MOVELEFT)
		{
			GiveInventory("TurnLeft", 1);
		}
		delay(1);
	}
}
//RIGHT
script 424 ENTER
{
	int buttons;
	while (TRUE)
	{
		buttons = GetPlayerInput(-1, INPUT_BUTTONS);
		if (buttons & BT_MOVERIGHT)
		{
			GiveInventory("TurnRight", 1);
		}
		delay(1);
		TakeInventory("TurnRight", 1);
	}
}
//USE
script 426 ENTER
{
	int buttons;
	while (TRUE)
	{
		buttons = GetPlayerInput(-1, INPUT_BUTTONS);
		if (buttons & BT_USE)
		{
			GiveInventory("PressedUse", 1);
		}
		delay(1);
	}
}
//JUMP
script 427 ENTER
{
	int buttons;
	while (TRUE)
	{
		buttons = GetPlayerInput(-1, INPUT_BUTTONS);
		if (buttons & BT_JUMP)
		{
			GiveInventory("PressedJump", 1);
		}
		delay(1);
	}
}
//MOUSE LEFT
script 431 ENTER
{
	int buttons;
	while (TRUE)
	{
		buttons = GetPlayerInput(-1, INPUT_YAW);
		if (buttons > 0)
		{
			GiveInventory("TurnMouseLeft", 1);
		}
		delay(1);
		TakeInventory("TurnMouseLeft", 1);
	}
}
//MOUSE RIGHT
script 430 ENTER
{
	int buttons;
	while (TRUE)
	{
		buttons = GetPlayerInput(-1, INPUT_YAW);
		if (buttons > 0)
		{
			GiveInventory("TurnMouseRight", 1);
		}
		delay(1);
		TakeInventory("TurnMouseRight", 1);
	}
}
Script 428 (VOID) NET
{
	delay (90);
	TakeInventory("FiredTankMainGun", 1);
}
Script 429 (VOID) NET
{
	delay (1);
	UnMorphActor(0, 0);
}
int playerprevioushealth;
int playerpreviousarmor;
int vehicleprevioushealth;
Script 129 (VOID)//Check if player is online.
{
	if	(GameType () > 0) 
	SetActorState(0,"IsOnline"); 
}
script 130 (VOID) NET
{
	vehicleprevioushealth = GetActorProperty(261, APROP_Health);
	delay(1);
}
script 131 (VOID) NET
{
	delay(1);
	playerprevioushealth = GetActorProperty( 0, APROP_Health);
	playerpreviousarmor = CheckInventory("Armor");
}
//Entering Heavy Machinegun
script 132 (VOID) NET
{
	delay(6);
	SetActorAngle (0, GetActorAngle (261));
	Thing_Move(0, 261, 1);
	GiveInventory("ArmorBonus", playerpreviousarmor);
	SetActorProperty(0, APROP_Health, playerprevioushealth);
	int thisgunmachinegunammo = CheckActorInventory(261, "HeavyMachinegunAmmo");
	GiveInventory("HeavyMachinegunAmmo", thisgunmachinegunammo);
	delay(1);
}
//leaving Heavy Machinegun
script 133 (VOID) NET
{
	delay (1);
	playerprevioushealth = GetActorProperty( 0, APROP_Health);
	playerpreviousarmor = CheckInventory("Armor");
	delay (1);
	int thisgunmachinegunammo = CheckInventory("HeavyMachinegunAmmo");
	GiveActorInventory(261, "HeavyMachinegunAmmo", thisgunmachinegunammo);
	TakeInventory("HeavyMachinegunAmmo", 400);
	Thing_Move(0, 264, 1);
	UnMorphActor(0, 0);
	delay (1);
	TakeInventory("Armor", 999);
	SetActorProperty(0, APROP_Health, playerprevioushealth);
	GiveInventory("ArmorBonus", playerpreviousarmor);
}
//Entering Tank
script 134 (VOID) NET
{
	delay(1);
	delay(5);
	SetActorAngle (0, GetActorAngle (261));
	Thing_Move(0, 261, 1);
	vehicleprevioushealth = GetActorProperty(261, APROP_Health);
	GiveInventory("StoredArmorInsideVehicle", playerpreviousarmor);
	GiveInventory("StoredHealthInsideVehicle", playerprevioushealth);
	SetActorProperty(0, APROP_Health, vehicleprevioushealth);
	int thisgunmachinegunammo = CheckActorInventory(261, "HeavyMachinegunAmmo");
	int thistankammo = CheckActorInventory(261, "TankAmmo");
	int thisvehicleHelicopterRocketAmmo = CheckActorInventory(261, "HelicopterRocketAmmo");
	int thisvehicleMechMortarAmmo = CheckActorInventory(261, "MechMortarAmmo");
	int thisvehicleMechLaserAmmo = CheckActorInventory(261, "MechLaserAmmo");
	int thisvehicleMechRocketAmmo = CheckActorInventory(261, "MechRocketAmmo");
	int vehiclepreviousbaseangle = CheckActorInventory(261, "TankBaseDirection");
	GiveInventory("HeavyMachinegunAmmo", thisgunmachinegunammo);
	GiveInventory("TankAmmo", thistankammo);
	GiveInventory("HelicopterRocketAmmo", thisvehicleHelicopterRocketAmmo);
	GiveInventory("MechMortarAmmo", thisvehicleMechMortarAmmo);
	GiveInventory("MechLaserAmmo", thisvehicleMechLaserAmmo);
	GiveInventory("MechRocketAmmo", thisvehicleMechRocketAmmo);
	SetUserVariable(0, "user_tankbasedirection", vehiclepreviousbaseangle);
	delay(1);
}
//leaving Tank
script 135 (VOID) NET
{
	int thisgunmachinegunammo = CheckInventory("HeavyMachinegunAmmo");
	int thistankammo = CheckInventory("TankAmmo");
	int thisvehicleHelicopterRocketAmmo = CheckInventory("HelicopterRocketAmmo");
	int thisvehicleMechMortarAmmo = CheckInventory("MechMortarAmmo");
	int thisvehicleMechLaserAmmo = CheckInventory("MechLaserAmmo");
	int thisvehicleMechRocketAmmo = CheckInventory("MechRocketAmmo");
	vehicleprevioushealth = GetActorProperty(0, APROP_Health);
	int vehiclepreviousbaseangle = GetUserVariable(0, "user_tankbasedirection");
	TakeInventory("HeavyMachinegunAmmo", 9999);
	TakeInventory("TankAmmo", 9999);
	TakeInventory("HelicopterRocketAmmo", 9999);
	TakeInventory("MechRocketAmmo", 9999);
	TakeInventory("MechLaserAmmo", 9999);
	TakeInventory("MechMortarAmmo", 9999);
	Thing_Move(0, 264, 1);
	UnMorphActor(0, 0);
	delay (1);
	int resetarmor = CheckInventory("StoredArmorInsideVehicle");
	int resethealth = CheckInventory("StoredHealthInsideVehicle");
	SetActorProperty(0, APROP_Health, resethealth);
	GiveInventory("ArmorBonus", resetarmor);
	SetActorProperty(261, APROP_Health, vehicleprevioushealth);
	GiveActorInventory(261, "HeavyMachinegunAmmo", thisgunmachinegunammo);
	GiveActorInventory(261, "TankAmmo", thistankammo);
	GiveActorInventory(261, "HelicopterRocketAmmo", thisvehicleHelicopterRocketAmmo);
	GiveActorInventory(261, "MechMortarAmmo", thisvehicleMechMortarAmmo);
	GiveActorInventory(261, "MechLaserAmmo", thisvehicleMechLaserAmmo);
	GiveActorInventory(261, "MechRocketAmmo", thisvehicleMechRocketAmmo);
	GiveActorInventory(261, "TankBaseDirection", vehiclepreviousbaseangle);
	SetActorProperty(261, APROP_Health, vehicleprevioushealth);
	TakeInventory("StoredHealthInsideVehicle", 9999);
	TakeInventory("StoredArmorInsideVehicle", 9999);
}
//Set Tank's new base angle after you leave it.
script 136 (VOID) NET
{
	delay (1);
	int thisvehiclecurrentbaseangle = CheckInventory("TankBaseDirection");
	delay (1);
	SpawnSpot("TankBaseStationed", 0, 0, thisvehiclecurrentbaseangle*256/360);
	delay (1);
}
//Set the current direction of a newly spawned tank.
script 137 (VOID) NET
{
	delay (1);
	int thisvehicleinitialbaseangle = GetActorAngle(0);
	int angleformulacalculation = thisvehicleinitialbaseangle >> 8;
	int angleformulacalculationlastpart = angleformulacalculation*360/256;
	delay (1);
	GiveInventory("TankBaseDirection", angleformulacalculationlastpart);
	delay (1);
}