#include "zcommon.acs"
#library "hq_cmn"

script 22 DEATH
{
	TakeInventory("Cash",random(10,100));
}

//Hud Scaler [Trigger::Spawn]
script 300 ENTER
{
	if (GetCVar("hud_scale")<1)
	{
		consolecommand("hud_scale 1");
	}
}

//Hud Scaler [Trigger::Respawn]
script 301 RESPAWN
{
	if (GetCVar("hud_scale")<1)
	{
		consolecommand("hud_scale 1");
	}
}

//Hud Scaler [Trigger::Open]
script 302 OPEN
{
	if (GetCVar("hud_scale")<1)
	{
		consolecommand("hud_scale 1");
	}
}

Script 511 (int movespeed)
{
	SetActorProperty(0,APROP_Speed,movespeed*65535/100);
}

Script 512 (void)
{
	SetResultValue(GameSkill());
}

script 784 (int a, int b, int c)
{
	if(a==2)
	{
		Thing_ChangeTID(0,4949+random(0,16384)); //Now I understand that this does not work, will have to think about tomorrow and now I have something too sleepy no idea how to do it the essence assign each id and then choose randomly from them at boys and girls are different ranges id
	}
	else
	{
		if(CheckActorClass(0,"GrowedCacodemonBoy"))
		{
		}
		else if(CheckActorClass(0,"GrowedCacodemonGirl"))
		{
		}
	}
}

//Spray Color Change Message
script 900 (void)
{
	SetFont("BIGFONT");
	If(CheckInventory("Spraycolor")==1)
	{
		HudMessage(s:"RED"; HUDMSG_FADEOUT, 0, CR_RED, 0.5, 0.44, 0.35, 0.35, 0.35);
	}
	If(CheckInventory("Spraycolor")==2)
	{
		HudMessage(s:"GREEN"; HUDMSG_FADEOUT, 0, CR_GREEN, 0.5, 0.44, 0.35, 0.35, 0.35);
	}
	If(CheckInventory("Spraycolor")==3)
	{
		HudMessage(s:"ORANGE"; HUDMSG_FADEOUT, 0, CR_ORANGE, 0.5, 0.44, 0.35, 0.35, 0.35);
	}
	If(CheckInventory("Spraycolor")==4)
	{
		HudMessage(s:"PURPLE"; HUDMSG_FADEOUT, 0, CR_PURPLE, 0.5, 0.44, 0.35, 0.35, 0.35);
	}
	If(CheckInventory("Spraycolor")==5)
	{
		HudMessage(s:"WHITE"; HUDMSG_FADEOUT, 0, CR_WHITE, 0.5, 0.44, 0.35, 0.35, 0.35);
	}
	If(CheckInventory("Spraycolor")==6)
	{
		HudMessage(s:"YELLOW"; HUDMSG_FADEOUT, 0, CR_YELLOW, 0.5, 0.44, 0.35, 0.35, 0.35);
	}
	If(CheckInventory("Spraycolor")==7)
	{
		HudMessage(s:"BLACK"; HUDMSG_FADEOUT, 0, CR_BLACK, 0.5, 0.44, 0.35, 0.35, 0.35);
	}
}

// Medic Health Regen
script 988 (void)
{
	AmbientSound("Healing", 127);
	GiveInventory("HealthBonus", 10);
	FadeTo(255, 0, 0, 1966, 0);
	Delay(5);
	FadeTo(255, 0, 0, 0, 0);
	Terminate;
}

//Cars
Script 998 (void) 
{
	UnMorphActor (0);
}
Script 997 (void)
{
	SetActorPitch(0, 0);
}
script 955 (void) //clientside
{
	SetActorAngle (0, GetActorAngle (0) - -0.06);
	delay(1);
}