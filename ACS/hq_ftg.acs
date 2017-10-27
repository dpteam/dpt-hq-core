#include "zcommon.acs"
#library "hq_ftg"

script 501 enter
{
	int player = PlayerNumber();
    delay(10);
    SetActivatorToTarget(0);

    if (PlayerClass(PlayerNumber()) == 13) // DartPower
    {
		While(1)
		{
			if((GetPlayerinput(-1,Input_Forwardmove) || GetPlayerInput(-1, INPUT_SIDEMOVE)) && (GetPlayerInput(-1,Input_Buttons) && BT_Speed))
			{
				TakeInventory("Stamina",1);
			}
			if(GetPlayerInput(-1, INPUT_Buttons) && BT_Jump)
			{
				TakeInventory("Stamina",10);
			}
			Delay(1);
		}
    }
}

script 502 enter
{
    if (PlayerClass(PlayerNumber()) == 13) // DartPower
    {
		While(1)
		{
			if(Checkinventory("Stamina")<=10)
			{
				SetActorProperty(0,APROP_Speed,65536/2);
			}
			else
			{
				SetActorProperty(0,APROP_Speed,65536);
			}
			Delay(1);
		}
	}
}

script 503 enter
{
    if (PlayerClass(PlayerNumber()) == 13) // DartPower
    {
		While(1)
		{
			GiveInventory("Stamina",1);
			Delay(5);
		}
	}
}