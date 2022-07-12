#include "CToolShell.h"

CToolShell::CToolShell()
{
}

CToolShell::~CToolShell()
{
}


void CToolShell::LoadImage()
{
	char fliename[] = ".\\source\\s11.png";
	tool_image = cvLoadImage(fliename, 1);
}


void CToolShell::InitPos(int x, int y)
{
	posx = x;
	posy = y;
}
