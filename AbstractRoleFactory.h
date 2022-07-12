#pragma once
#include "CPlayer.h"
#include "CSkin.h"
class AbstractRoleFactory
{
public:
	AbstractRoleFactory();
	~AbstractRoleFactory();
	virtual CSkin*  Select(int type) = 0;
	virtual CPlayer* BuildRole(int type) = 0;
};

