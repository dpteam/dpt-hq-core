// ACS Source Code
#include "zcommon.acs"
#library "hq_sndbx"

// Includes

// Defines
#define scrGGunPuntRecoil 1
#define scrGGunPunt 2
#define scrGGunGrab 3
#define scrRefire 4

// Variables

// Scripts
Script "Commands" ENTER
{
	ZanSetCVar("sv_ggun_maxweight", 200);
	ZanSetCVar("sv_ggun_strength", 1);
	ZanSetCVar("sv_ggun_forcegrab", 0);
}

Script "GiveUniquePlayerTIDs" ENTER
{
	if(!ActivatorTID())
		Thing_ChangeTID(0, ZanUniqueTID(-32768, 32767));
}

Script scrGGunPuntRecoil (int tid, int noSound)
{
	if (!noSound)
	{
		int temp = ActivatorTID();
		SetActivator(tid);
		ActivatorSound("ggun/launch", 127);
		SetActivator(temp);
	}
	int pitch = GetActorPitch(tid);
	SetActorPitch(tid, pitch-0.05);
	while (GetActorPitch(tid) < pitch)
	{
		SetActorPitch(tid, GetActorPitch(tid)+0.005);
		Delay(1);
	}
}

Script scrGGunPunt (int pTID)
{
	if (!pTID)
	{
		pTID = ActivatorTID();
		SetActivatorToTarget(0);
	}
	if (ActivatorTID() == pTID)
	{
		TakeInventory("GGunIsGrabbing", 1);
		Terminate;
	}
	ThrustThing(GetActorAngle(pTID) >> 8, 10 * GetCVar("sv_ggun_strength"), 1, 0);
	ThrustThingZ(0, 5 * GetCVar("sv_ggun_strength"), 0, 0);
	ACS_ExecuteAlways(scrGGunPuntRecoil, 0, pTID);
	Thing_Damage2(0, 1 * GetCVar("sv_ggun_strength"), "GGunPunt");
}

Script scrGGunGrab (void)
{
	int pX, pY, pZ, pA, pP, pH, gX, gY, gZ, defGrav, altReleased;
	int vX, vY, vZ, breakLoop, magnitude, strength = GetCVar("sv_ggun_strength");
	int tAng, tLen, tX, tY, tZ, objBeenWithinRange, temp;
	int pNum = PlayerNumber();
	int pTID = ActivatorTID();
	SetActivatorToTarget(0);
	
	if (ActivatorTID() == pTID)
		breakLoop = 1;
	
	if ((GetActorProperty(0, APROP_Mass) > GetCVar("sv_ggun_maxweight")))
		breakLoop = 1;
	
	if (CheckInventory("NoGGunPickup") && !GetCVar("sv_ggun_forcegrab"))
		breakLoop = 1;
	
	if (!ActivatorTID())
		Thing_ChangeTID(0, ZanUniqueTID(-32768, 32767));
	
	GiveInventory("HeldByGGun", 1);
	defGrav = GetActorProperty(0, APROP_Gravity);
	
	pX = GetActorX(pTID);
	pY = GetActorY(pTID);
	pZ = GetActorZ(pTID);
	pA = GetActorAngle(pTID);
	pP = GetActorPitch(pTID) * -1;
	pH = 56;
		
	gX = (pX / 65536 + NewCos(pA) / 1024) * 65536;
	gY = (pY / 65536 + NewSin(pA) / 1024) * 65536;
	gZ = (pZ / 65536 + (pH / 2) / 65536 + NewSin(pP) / 1024) * 65536;
	
	while (!breakLoop)
	{
		SetActorProperty(0, APROP_Gravity, 0);
		if ((GetActorProperty(0, APROP_Mass) > GetCVar("sv_ggun_maxweight")))
			breakLoop = 1;
		
		pX = GetActorX(pTID);
		pY = GetActorY(pTID);
		pZ = GetActorZ(pTID);
		pA = GetActorAngle(pTID);
		pP = GetActorPitch(pTID) * -1;
		
		gX = (pX / 65536 + NewCos(pA) / 1024) * 65536;
		gY = (pY / 65536 + NewSin(pA) / 1024) * 65536;
		gZ = (pZ / 65536 + (pH / 2) / 65536 + NewSin(pP) / 1024) * 65536;
		
		vX = gX - GetActorX(0);
		vY = gY - GetActorY(0);
		vZ = gZ - GetActorZ(0);
		
		magnitude = magnitudeThree(vX >> 16, vY >> 16, vZ >> 16) * strength;
		
		if (magnitude != 0)
		{
			vX = vX / magnitude;
			vY = vY / magnitude;
			vZ = vZ / magnitude;
		}
        else
		{
            vX = 0;
			vY = 0;
			vZ = 0;
        }
		
		tX = GetActorX(0) - gX;
		tY = GetActorY(0) - gY;
		tZ = GetActorZ(0) - gZ;
		
		tAng = VectorAngle(tX, tY);
		if (((tAng + 0.125) % 0.5) > 0.25)
			tLen = FixedDiv(tY, Sin(tAng));
		else
			tLen = FixedDiv(tX, Cos(tAng));
		
		tAng = vectorangle(tLen, tZ);
		if (((tAng + 0.125) % 0.5) > 0.25)
			tLen = FixedDiv(tZ, Sin(tAng));
		else
			tLen = FixedDiv(tLen, Cos(tAng));
		
		strength = tLen / 65536;
		
		if ((strength <= 128) && !objBeenWithinRange)
			objBeenWithinRange = 1;
		
		if ((strength > 256) && objBeenWithinRange)
			breakLoop = 1;
		
		if (!(GetPlayerInput(pNum, INPUT_BUTTONS) & BT_ALTATTACK) && !objBeenWithinRange)
			breakLoop = 1;
		
		strength = GetCVar("sv_ggun_strength");
		
		SetActorVelocity(0, vX * strength, vY * strength, 0, true, true);
		SetActorVelocity(0, GetActorVelX(0), GetActorVelY(0), vZ * 2 * strength, false, true);
		
		if (GetPlayerInput(pNum, INPUT_BUTTONS) & BT_ATTACK)
		{
			ACS_ExecuteAlways(scrGGunPunt, 0, pTID);
			breakLoop = 1;
		}
		
		if (!GetActorProperty(pTID, APROP_Health))
			breakLoop = 1;
		
		Delay(1);
		
		if (GetPlayerInput(pNum, INPUT_BUTTONS) & BT_ALTATTACK)
		{
			if (altReleased)
			{
				temp = ActivatorTID();
				SetActivator(pTID);
				ActivatorSound("ggun/drop", 127);
				SetActivator(temp);
				breakLoop = 1;
			}
		}
		else
			altReleased = 1;
	}
	TakeInventory("HeldByGGun", 1);
	SetActorProperty(0, APROP_Gravity, defGrav);
	SetActivator(pTID);
	TakeInventory("GGunIsGrabbing", 1);
}

Script scrRefire (void)
{
	int input = GetPlayerInput(-1, INPUT_BUTTONS);
	SetResultValue((input & BT_ATTACK) || (input & BT_ALTATTACK));
}

// Functions
Function int NewCos (int angle)
{
	if (angle > 32767)
	{
		angle *= -1;
		angle += 65536;
	}
	return Cos(angle);
}

Function int NewSin (int angle)
{
	if (angle > 49152)
	{
		angle *= -1;
		angle += 32768;
	}
	angle += 16384;
	return -NewCos(angle);
}

Function int magnitudeThree (int x, int y, int z)
{
    return sqrt_i(x * x + y * y + z * z);
}

Function int sqrt_i (int number)
{
    if (number <= 3)
		return number > 0;
	
    int oldAns = number >> 1, newAns = (oldAns + number / oldAns) >> 1;
	
    while (newAns < oldAns)
    {
        oldAns = newAns;
        newAns = (oldAns + number / oldAns) >> 1;
    }
	
    return oldAns;
}

Function int ZanUniqueTID (int tid, int limit)
{
    for ( ; tid < limit; tid++)
    {
        if (!ThingCount (T_NONE, tid))
            return tid;
    }
    return 0;
}

Function void ZanSetCVar (str cvar, int value)
{
	ConsoleCommand(StrParam(s:"set ", s:cvar, s:" ", i:value));
}

Function void ZanSetCVarString (str cvar, str value)
{
	ConsoleCommand(StrParam(s:"set ", s:cvar, s:" ", s:value));
}

str Enemies[18] = {
	"Sandbox-ArachnotronEnemy",
	"Sandbox-ArchvileEnemy",
	"Sandbox-BaronOfHellEnemy",
	"Sandbox-HellKnightEnemy",
	"Sandbox-CacodemonEnemy",
	"Sandbox-CyberdemonEnemy",
	"Sandbox-DemonEnemy",
	"Sandbox-SpectreEnemy",
	"Sandbox-ChaingunGuyEnemy",
	"Sandbox-DoomImpEnemy",
	"Sandbox-FatsoEnemy",
	"Sandbox-LostSoulEnemy",
	"Sandbox-PainElementalEnemy",
	"Sandbox-RevenantEnemy",
	"Sandbox-ShotgunGuyEnemy",
	"Sandbox-SpiderMastermindEnemy",
	"Sandbox-WolfensteinSSEnemy",
	"Sandbox-ZombieManEnemy",
};

str Friends[18] = {
	"Sandbox-ArachnotronFriend",
	"Sandbox-ArchvileFriend",
	"Sandbox-BaronOfHellFriend",
	"Sandbox-HellKnightFriend",
	"Sandbox-CacodemonFriend",
	"Sandbox-CyberdemonFriend",
	"Sandbox-DemonFriend",
	"Sandbox-SpectreFriend",
	"Sandbox-ChaingunGuyFriend",
	"Sandbox-DoomImpFriend",
	"Sandbox-FatsoFriend",
	"Sandbox-LostSoulFriend",
	"Sandbox-PainElementalFriend",
	"Sandbox-RevenantFriend",
	"Sandbox-ShotgunGuyFriend",
	"Sandbox-SpiderMastermindFriend",
	"Sandbox-WolfensteinSSFriend",
	"Sandbox-ZombieManFriend",
};

#define SPAWNED_TID 1423
#define LIMIT 255

script 100 (int Number)
{
	Spawn(Friends[Number], GetActorX (0), GetActorY(0), GetActorZ(0), SPAWNED_TID, true);
}

script 102 (int Number)
{
	Spawn(Enemies[Number], GetActorX (0), GetActorY(0), GetActorZ(0), SPAWNED_TID, true);
}

script 101 (void)
{
	if (ThingCount(0, SPAWNED_TID) >= LIMIT)
	{
		SetHudSize(640, 480, 0);
		SetFont("BIGFONT");
		HudMessage(s:"You may spawn only 255 monsters max!"; HUDMSG_FADEOUT, 10, CR_RED, 320.0, 240.0, 1.0);
		SetResultValue(0);
		terminate;
	}
	SetResultValue(255);
}
