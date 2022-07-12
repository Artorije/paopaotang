#include "CToolDecoratorPurplePotion.h"

CToolDecoratorPurplePotion::CToolDecoratorPurplePotion(CTool* tool):CToolDecorator(tool)
{
}

CToolDecoratorPurplePotion::~CToolDecoratorPurplePotion()
{
}


void CToolDecoratorPurplePotion::LoadImage()
{
	CToolDecorator::LoadImage();
	DecorateColor();
}


void CToolDecoratorPurplePotion::DecorateColor()
{
	char fliename[] = ".\\source\\s12.1.png";
	tool_image = cvLoadImage(fliename, 1);
}


void CToolDecoratorPurplePotion::InitPos(int x, int y)
{
	posx = x;
	posy = y;
}
