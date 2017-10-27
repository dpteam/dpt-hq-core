#include "zcommon.acs"
#library "hq_laser"

#Define LaserDist 256
#Define LaserSpeed 0.015
#Define LaserAmount 8
#Define LaserMove 1
#Define LaserTime 35

Script 384 (Int Target)
{
	Int px, py, pz, calc;
	px = GetActorX(Target); py = GetActorY(Target); pz = GetActorZ(Target);
	For(Int i = 1; i != LaserAmount + 1; i++)
	{
		calc = FixedMul(FixedDiv(1.0, LaserAmount), i);
		Spawn("BlueBeam", px + Cos(calc) * 96, py + Sin(calc) * 96, pz, -150000 + i, 0);
	}
	Int d, a; d = LaserDist;
	While(d > 0)
	{
		For(Int ii = 1; ii != LaserAmount + 1; ii++)
		{
			calc = FixedMul(FixedDiv(1.0, LaserAmount), ii) + a;
			SetActorPosition(-150000 + ii, px + Cos(calc) * d, py + Sin(calc) * d, PZ, 0);
		}
		d -= LaserMove; a += LaserSpeed;
		Delay(Const:1);
	}
	Delay(LaserTime);
	Spawn("BlueStrike", px, py, pz, 0, 0);
	For(Int dest = 1; dest != LaserAmount + 1; dest++)
	Thing_Remove(-150000 + dest);
}