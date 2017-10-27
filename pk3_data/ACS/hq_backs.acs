#include "zcommon.acs"
#library "hq_backs"

#libdefine TID_START 600

function int getintegeractorx(int tid) {
	return GetActorX(tid) >> 16;
}

function int getintegeractory(int tid) {
	return GetActorY(tid) >> 16;
}

function int getintegeractorz(int tid) {
	return GetActorZ(tid) >> 16;
}

function int getplayertid(int number) {
	return TID_START+number;
}

function int sqractordistance(int fromTID, int toTID) {
	int x = GetIntegerActorX(fromTID) - GetIntegerActorX(toTID);
	int y = GetIntegerActorY(fromTID) - GetIntegerActorY(toTID);
	int z = GetIntegerActorZ(fromTID) - GetIntegerActorZ(toTID);

	return x * x + y * y + z * z;
}

function int findplayerback(int tid, int minDistance) {
	int selected = -1;
	minDistance = minDistance * minDistance;
	
	for (int i = 0; i < 32; i++) {
		int candidateTID = GetPlayerTID(i);
		if (candidateTID != tid) {
			int distance = SqrActorDistance(tid, candidateTID);        
			if (distance <= minDistance) {
				int vang = VectorAngle (GetActorX (candidateTID) - GetActorX (tid), GetActorY (candidateTID) - GetActorY (tid));
				int screenAngle = (vang - GetActorAngle(tid) + 1.0) % 1.0;
				int orientationAngle = (GetActorAngle(candidateTID) - GetActorAngle(tid) + 1.0) % 1.0;

				//if ((screenAngle < 0.075 || screenAngle > 0.925) && 
				if ((screenAngle < 0.072 || screenAngle > 0.877) && 
						//(orientationAngle < 0.1 || orientationAngle > 0.9)) {
						(orientationAngle < 0.13 || orientationAngle > 0.87)) {
					selected = i;
					break;
					//minDistance = distance;
				}
			}
		}
	}
	return selected;
}

script 555 (void) // Backstab script
{
	if (FindPlayerBack(ActivatorTID(), 72) != -1) {
		SetResultValue(TRUE);
		print(s:"TRUE");
	} else {
		SetResultValue(FALSE);
		print(s:"FALSE");
	}
}
