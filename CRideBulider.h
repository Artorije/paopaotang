#pragma once
#include "CRideBulider.h"
#include "CRide.h"
#include "CRideUFO.h"
#include "CPlayer.h"
#include "MMap.h"
class CRideBulider
{
public:
	CRideBulider();
	~CRideBulider();
	CRide* ride;
	CPlayer* player_builder;
	CRide* Construct(CPlayer *player);
	void SetPlayer(CPlayer* player);
	void DrawtoBK(IplImage* pbk);
};

