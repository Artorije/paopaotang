#include "CSkinFactory.h"

CSkinFactory::CSkinFactory()
{
}

CSkinFactory::~CSkinFactory()
{
}


CSkin* CSkinFactory::Select(int type)
{
	switch (type)
	{
	case 1:
		CRedSkin * redskin;
		redskin = new CRedSkin;
		redskin->LoadImage();
		return(redskin);
		break;
	case 2:
		CSisterSkin * sisterskin;
		sisterskin = new CSisterSkin;
		sisterskin->LoadImage();
		return(sisterskin);
		break;
	case 3:
		CYellowSkin * yellowskin;
		yellowskin = new CYellowSkin;
		yellowskin->LoadImage();
		return(yellowskin);
		break;
	case 4:
		CGreenSkin * greenskin;
		greenskin = new CGreenSkin;
		greenskin->LoadImage();
		return(greenskin);
	default:
		return nullptr;
		break;
	}
}

CPlayer* CSkinFactory::BuildRole(int type)
{
	return nullptr;
}
