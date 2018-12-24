#include "zcommon.acs"
#library "hq_weath"

#define PlayerTID 255 //player TID assigned - this can be changed.

//WeatherFX by Jon Washburn
//Feel free to use this in your own projects, just give credit.
//Also drop me a line at jon-washburn@nyc.rr.com if you like it!
int WFX_Upper_TID[100]; //Upper left bound thing for weather zone
int WFX_Lower_TID[100]; //Lower right bound thing for weather zone
str WFX_Type[100]; //Weather effect type TID array
int WFX_Density[100]; //Weather zone density
int WFX_Distance[100]; //Distance at which the weather fades out
int WFX_IgnorePlayer[100]; //1 = ignore player distance, 0 = use player distance
int WFX_Active[100]; //1 = weather zone is active, 0 = weather zone is inactive
int WFX_WeatherZones; //number of weather zones in the map
int WFX_NoWeather=0; //Adjusted Automatically using scripts

//This is the main weather spawning function
function void SpawnWeatherEffect (int UpperLeft, int LowerRight, str WeatherType, int Distance, int Density, int IgnorePlayer)
{
	int xMin=0;
	int xMax=0;
	int yMin=0;
	int yMax=0;
	int xSpawnMin=0;
	int xSpawnMax=0;
	int ySpawnMin=0;
	int ySpawnMax=0;
	int xPlay=0;
	int yPlay=0;
	int xSpawn=0;
	int ySpawn=0;
	int zSpawn=0;
	//Get default spawn x and y max/min from map spots
	xSpawnMin=GetActorX(UpperLeft)/65536;
	xSpawnMax=GetActorX(LowerRight)/65536;
	zSpawn=GetActorZ(UpperLeft)/65536;
	ySpawnMin=GetActorY(LowerRight)/65536;
	ySpawnMax=GetActorY(UpperLeft)/65536;
	xMax=xSpawnMax;
	xMin=xSpawnMin;
	yMax=ySpawnMax;
	yMin=ySpawnMin;
	//Get player coordinates, if the weather zone isn't ignoring player position
	if (IgnorePlayer==0)
	{
		xPlay=GetActorX(PlayerTID)/65536;
		yPlay=GetActorY(PlayerTID)/65536;
		//Calculate max/min values based on the position of the player.
		//This attempts to center the effects around the player.
		xMax=xPlay+Distance;
		xMin=xPlay-Distance;
		yMax=yPlay+Distance;
		yMin=yPlay-Distance;
	}
	//Prevent effects from spawning outside the area bound by the spawn spots.
	if (xMax>=xSpawnMax) {xMax=xSpawnMax;}
	if (xMin<=xSpawnMin) {xMin=xSpawnMin;}
	if (yMax>=ySpawnMax) {yMax=ySpawnMax;}
	if (yMin<=ySpawnMin) {yMin=ySpawnMin;}
	for (int i=0;i < Density;i++)
	{
		xSpawn=Random(xMin,xMax);
		ySpawn=Random(yMin,yMax);
		if (xSpawn <= xMax && xSpawn >= xMin && ySpawn <= yMax && ySpawn >= yMin)
		{
			Spawn(WeatherType,(xSpawn*65536),(ySpawn*65536),(zSpawn*65536));
		}
	}
}

//Set the player TID to get position information
script 940 enter
{
	Thing_ChangeTID (0, PlayerTID) ;
	if (CheckInventory("Action_WeatherToggle")==0) GiveInventory("Action_WeatherToggle",1);
	if (CheckInventory("Flag_NoWeather")==1) WFX_NoWeather=1;
	if (CheckInventory("Flag_NoWeather")==0) WFX_NoWeather=0;
}

//Switch the weatherFX stuff off and on
script 941 (void)
{
	if (CheckInventory("Flag_NoWeather")==1) WFX_NoWeather=1;
	if (CheckInventory("Flag_NoWeather")==0) WFX_NoWeather=0;
}

//This is the map script to spawn weather effects
script 950 (int DelayTime)
{
	while(true)
	{
		for(int i=0;i<WFX_WeatherZones;i++)
		{
			if (WFX_Active[i]==1 && WFX_NoWeather==0) {SpawnWeatherEffect(WFX_Upper_TID[i],WFX_Lower_TID[i],WFX_Type[i],WFX_Distance[i],WFX_Density[i],WFX_IgnorePlayer[i]);}
		}
		delay(DelayTime);
	}
}