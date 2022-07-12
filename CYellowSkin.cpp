#include "CYellowSkin.h"

CYellowSkin::CYellowSkin()
{
}

CYellowSkin::~CYellowSkin()
{
}


void CYellowSkin::LoadImage()
{
	int i;
	char flie1[] = ".\\source\\yellow_role\\y00.png";
	for (i = 0; i < 24; i++)
	{
		sprintf_s(flie1, ".\\source\\yellow_role\\y%02d.png", i);
		m_skin[i] = cvLoadImage(flie1, 1);
	}
	char file2[] = ".\\source\\yellow_role\\y34.png";
	m_shallow = cvLoadImage(file2, 1);
}
