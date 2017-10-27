#include "zcommon.acs"
#library "hq_dark"

#define MaxPlayers 64
int Playerstun[MaxPlayers];
int TerminateScript[1000];

script 533 (void)
{
	SetHudSize(320,200,1);
	delay(1);
	setfont("XBREAK");
	hudmessage(s:"A"; HUDMSG_FADEOUT, 0, CR_UNTRANSLATED, 150.0, 100.0, 4.0);
	delay(50);
}

Script 986 (void)
{
	if (TerminateScript[986])
	Terminate;
	SetPlayerProperty (0, 1, 0);
	GiveInventory("CreeperStunCheck",1);
	fadeto(255, 255, 255, 0.03, 0.0);
	Playerstun[PlayerNumber()] = 42;
	for(int i = 42; i > 0; i--)
	{
		if(i != Playerstun[PlayerNumber()])
		terminate;
		Playerstun[PlayerNumber()]--;
		Delay(1);
	}
	Fadeto(255, 255, 255, 0.0, 0.0);
	TakeInventory("CreeperStunCheck",1);
	SetPlayerProperty (0, 0, 0);
}

SCRIPT 999 (VOID)
{
	SETACTORPROPERTY(0, APROP_SPEED, 0.5);
}

SCRIPT 1998 (VOID)
{
	SETACTORPROPERTY(0, APROP_SPEED, 1.0);
}

SCRIPT 1997 (VOID)
{
	SETHUDSIZE(1280, 1024, 1);
	SETFONT("CREEC0");
	LOCALAMBIENTSOUND("CREEPERATTACK",127);
	FOR (INT Y = 3072; Y > 1620; Y -= 150) {         
		HUDMESSAGE(s:"A"; HUDMSG_FADEOUT, 666, CR_UNTRANSLATED, 1100.0, (Y*1.0), 0.2, 0.2);
		DELAY(1);
	}
	DAMAGETHING(255);
}