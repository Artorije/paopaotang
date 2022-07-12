#pragma once
#include "CPlayer.h"
class CPirate :
    public CPlayer
{
public:
	CPirate();
	~CPirate();
	void InitPos(int x, int y);
};

