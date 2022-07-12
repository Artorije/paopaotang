#include "CToolPower.h"

CToolPower::CToolPower()
{
}

CToolPower::~CToolPower()
{
}


void CToolPower::LoadImage()
{
	char fliename[] = ".\\source\\s12.png";
	tool_image = cvLoadImage(fliename, 1);
}


void CToolPower::InitPos(int x, int y)
{
	posx = x;
	posy = y;
}
