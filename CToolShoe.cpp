#include "CToolShoe.h"

CToolShoe::CToolShoe()
{
}

CToolShoe::~CToolShoe()
{
}


void CToolShoe::LoadImage()
{
	char fliename[] = ".\\source\\s13.png";
	tool_image = cvLoadImage(fliename, 1);
}


void CToolShoe::InitPos(int x, int y)
{
	posx = x;
	posy = y;
}
