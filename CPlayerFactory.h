#pragma once
#include"CRedbaby.h"
#include"CPirate.h"
#include "CSkin.h"
#include "AbstractRoleFactory.h"

class CPlayerFactory :
    public AbstractRoleFactory
{
public:
    CPlayerFactory();
    ~CPlayerFactory();
    CSkin* Select(int type);
    CPlayer* BuildRole(int type);
};

