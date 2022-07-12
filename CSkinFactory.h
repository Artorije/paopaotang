#pragma once
#include "AbstractRoleFactory.h"
#include "CPlayer.h"
#include "CSkin.h"
#include "CRedSkin.h"
#include "CSisterSkin.h"
#include "CYellowSkin.h"
#include "CGreenSkin.h"
class CSkinFactory :
    public AbstractRoleFactory
{
public:
    CSkinFactory();
    ~CSkinFactory();
    CSkin* Select(int type);
    CPlayer* BuildRole(int type);
};

