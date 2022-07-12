#include "CPlayerFactory.h"

CPlayerFactory::CPlayerFactory()
{
}

CPlayerFactory::~CPlayerFactory()
{
}

CSkin* CPlayerFactory::Select(int type)
{
    return nullptr;
}

CPlayer* CPlayerFactory::BuildRole(int type)
{
	switch (type)
	{
	case 1:
		CRedbaby * role1;
		role1 = new CRedbaby;
		role1->InitPos(11, 11);
		return(role1);
		break;
	case 2:
		CPirate * role2;
		role2 = new CPirate;
		role2->InitPos(2, 2);
		return(role2);
		break;
	default:
		return nullptr;
		break;
	}
}
