#include "zcommon.acs"
#library "hq_mcam"

#define C_TIDX		1000	//Default camera tid
#define MAX_RX		220	//Maximum radius (or distance from the player)
#define ADJUST_R	12	//Amount to adjust the camera by
#define VIEW_HEIGHTX	150.0	//The approximate height of the player's view


#define VIEW_HEIGHTXMECH	200.0	//The approximate height of the player's view
#define MAX_RXMECH		300	//Maximum radius (or distance from the player)


bool camera_mode2[8];		//Variable for turning the camera on or off.
	
Script 111(VOID)
{
setfont("TNHSA0");
	hudmessage(s:"A"; 
				HUDMSG_PLAIN, 0, CR_UNTRANSLATED, 0.5, 0.57, 1.0);
	delay(40 * 6);
}

Script 656(VOID)
{
setfont("CONFONT");
 int mgunammo = CheckInventory("HeavyMachinegunAmmo");
	hudmessage(d: mgunammo; HUDMSG_PLAIN, 0, CR_LIGHTBLUE, 0.38, 0.80, 0.06);
 int rocketammo = CheckInventory("MechRocketAmmo");
	hudmessage(d: rocketammo; HUDMSG_PLAIN, 0, CR_LIGHTBLUE, 0.65, 0.80, 0.06);
int laserammo = CheckInventory("MechLaserAmmo");
	hudmessage(d: laserammo; HUDMSG_PLAIN, 0, CR_LIGHTBLUE, 0.38, 0.94, 0.06);	
int mortarammo = CheckInventory("MechMortarAmmo");
	hudmessage(d: mortarammo; HUDMSG_PLAIN, 0, CR_LIGHTBLUE, 0.65, 0.94, 0.06);	
int mechhealth = GetActorProperty(0, APROP_HEALTH);
	hudmessage(d: mechhealth; HUDMSG_PLAIN, 0, CR_LIGHTBLUE, 0.50, 0.96, 0.06);		
	delay(2);
}
	
Script 877 (VOID)
{
	camera_mode2[PlayerNumber ()] = ON;
	ACS_ExecuteAlways (801, 0, PlayerNumber ());
}


Script 801 (int p_num)
{
	int r = MAX_RX;
	
	while (camera_mode2[p_num] == ON)
	{	
		int a = GetActorAngle (0);
		int p = GetActorPitch (0);
		int x = GetActorX (0);
		int y = GetActorY (0);
		int z = GetActorZ (0) + VIEW_HEIGHTX;
		int xyr = r * cos (p) >> 16;
		
		if (!ThingCountName ("chasecam3", C_TIDX+p_num))
		{
			while (!Spawn ("chasecam3", x-cos(a)*xyr, y-sin(a)*xyr, z+sin(p)*r, C_TIDX+p_num, a >> 8) && r > 0)
			{
				r -= ADJUST_R;
				xyr = cos (p) * r >> 16;
			}
			
			if (ThingCountName ("chasecam3", C_TIDX + p_num))
				ChangeCamera (C_TIDX + p_num, 0, 0);
			else
			{
				camera_mode2[p_num] = OFF;
				print (s:"Camera script failed to initialize.");
			}
		}





	        else
		{
			while (!SetActorPosition (C_TIDX+p_num, x-cos(a)*xyr, y-sin(a)*xyr, z+sin(p)*r, 0) && r > 0)
			{
				r -= ADJUST_R;
				xyr = cos (p) * r >> 16;
			}
			
			SetActorAngle (C_TIDX + p_num, a);
			SetActorPitch (C_TIDX + p_num, p);
			
			if (r < MAX_RX) 
                                r += ADJUST_R;
		}
		
		delay (1);
	}
}




Script 871 (VOID)
{
	camera_mode2[PlayerNumber ()] = OFF;
	Thing_Remove (C_TIDX + PlayerNumber ());
}

Script 820 (int p_num) DISCONNECT
{
       camera_mode2[p_num] = OFF;
       Thing_Remove (C_TIDX + p_num);
}







Script 887 (VOID)
{
	camera_mode2[PlayerNumber ()] = ON;
	ACS_ExecuteAlways (811, 0, PlayerNumber ());
}


Script 811 (int p_num)
{
	int r = MAX_RXMECH;
	
	while (camera_mode2[p_num] == ON)
	{	
		int a = GetActorAngle (0);
		int p = GetActorPitch (0);
		int x = GetActorX (0);
		int y = GetActorY (0);
		int z = GetActorZ (0) + VIEW_HEIGHTXMECH;
		int xyr = r * cos (p) >> 16;
		
		if (!ThingCountName ("chasecam3", C_TIDX+p_num))
		{
			while (!Spawn ("chasecam3", x-cos(a)*xyr, y-sin(a)*xyr, z+sin(p)*r, C_TIDX+p_num, a >> 8) && r > 0)
			{
				r -= ADJUST_R;
				xyr = cos (p) * r >> 16;
			}
			
			if (ThingCountName ("chasecam3", C_TIDX + p_num))
				ChangeCamera (C_TIDX + p_num, 0, 0);
			else
			{
				camera_mode2[p_num] = OFF;
				print (s:"Camera script failed to initialize.");
			}
		}





	        else
		{
			while (!SetActorPosition (C_TIDX+p_num, x-cos(a)*xyr, y-sin(a)*xyr, z+sin(p)*r, 0) && r > 0)
			{
				r -= ADJUST_R;
				xyr = cos (p) * r >> 16;
			}
			
			SetActorAngle (C_TIDX + p_num, a);
			SetActorPitch (C_TIDX + p_num, p);
			
			if (r < MAX_RXMECH) 
                                r += ADJUST_R;
		}
		
		delay (1);
	}
}




Script 881 (VOID)
{
	camera_mode2[PlayerNumber ()] = OFF;
	Thing_Remove (C_TIDX + PlayerNumber ());
}

Script 830 (int p_num) DISCONNECT
{
       camera_mode2[p_num] = OFF;
       Thing_Remove (C_TIDX + p_num);
}
