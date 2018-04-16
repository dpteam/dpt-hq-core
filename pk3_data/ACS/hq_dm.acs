#include "zcommon.acs"
#library "hq_dm"

script 557 ENTER
{
	int player = PlayerNumber();
	delay(10);
	SetActivatorToTarget(0);
	//if(GetCvar("Deathmatch")>0 || GetCvar("TeamPlay")>0 || GetCvar("Terminator")>0 || GetCvar("Possession")>0 || GetCvar("TeamPossession")>0 || GetCvar("LastManStanding")>0 || GetCvar("TeamLMS")>0 || GetCvar("CTF")>0 || GetCvar("OneFlagCTF")>0 || GetCvar("SkullTag")>0 || GetCvar("Duel")>0 || GetCvar("TeamGame")>0 || GetCvar("Domination")>0)
	//if(GetCvar("Deathmatch")==1 || GetCvar("TeamPlay")==1 || GetCvar("Terminator")==1 || GetCvar("Possession")==1 || GetCvar("TeamPossession")==1 || GetCvar("LastManStanding")==1 || GetCvar("TeamLMS")==1 || GetCvar("CTF")==1 || GetCvar("OneFlagCTF")==1 || GetCvar("SkullTag")==1 || GetCvar("Duel")==1 || GetCvar("TeamGame")==1 || GetCvar("Domination")==1)
	if(GameType()==GAME_NET_DEATHMATCH)
	{
		if(PlayerClass(PlayerNumber()) == 5) // Mingebag
		{
			SetFont("DBIGFONT");
			HudMessage(s:"DIE! YOU CANT USE THIS CLASS IN DM-LIKE GAME MODES!";HUDMSG_FADEOUT,0,CR_RED,0.5, 0.5, 1.0, 1.0, 1.0);
			DamageThing(255);
		}
		//Core
		TakeInventory("Dick",1);
		TakeInventory("Pussy",1);
		TakeInventory("BlueSprayPaint",1);
		TakeInventory("RedSprayPaint",1);
		TakeInventory("GreenSprayPaint",1);
		TakeInventory("SprayPaint",1);
		TakeInventory("IonRifle",1);
		//Cop
		TakeInventory("JailPistol",1);
		//Healer
		TakeInventory("Curing_Cannon",1);
		//DartPower
		TakeInventory("Icegun",1);
		TakeInventory("UACM360",1);
		TakeInventory("Gothic_Shotgun",1);
		//LazyPanda
		TakeInventory("DOOM42k16SSG",1);
		TakeInventory("BFG10K",1);
		//NighMare
		TakeInventory("MurderKnife",1);
		//Benellus
		TakeInventory("DUMP3Wingman",1);
		TakeInventory("DUMP3Tyrant",1);
		TakeInventory("DUMP3DualModeRifle",1);
		TakeInventory("DUMP3CactusPipe",1);
		TakeInventory("DUMP3Fusion_Gun",1);
		TakeInventory("DUMP3SirusBusterCannon",1);
		TakeInventory("DUMP3Gibmaker",1);
		TakeInventory("DUMP3RevenantBox",1);
		//Ovlab
		TakeInventory("ScatterPistol",1);
		TakeInventory("Shredder",1);
		TakeInventory("Deviation",1);
		TakeInventory("BHGen",1);
		TakeInventory("MultiProjectileWeapon",1);
		TakeInventory("Karasawa",1);
		TakeInventory("Quadvolgue",1);
		TakeInventory("M16",1);
		TakeInventory("SMG",1);
		TakeInventory("DoubleSMG",1);
		//Oppressor1338
		TakeInventory("STFBFG9000",1);
		TakeInventory("Powercube",1);
		//Zendos
		TakeInventory("ImpalerXBow",1);
	}
}

script 558 RESPAWN
{
	ACS_Execute(557,0,0,0,0);
}