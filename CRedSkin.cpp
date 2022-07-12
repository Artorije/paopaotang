#include "CRedSkin.h"

CRedSkin::CRedSkin()
{
}

CRedSkin::~CRedSkin()
{
}


void CRedSkin::LoadImage()
{
	int i;
	char flie1[] = ".\\source\\red_role\\r00.png";
	for (i = 0; i < 24; i++)
	{
		sprintf_s(flie1, ".\\source\\red_role\\r%02d.png", i);
		m_skin[i] = cvLoadImage(flie1, 1);
	}
	char file2[] = ".\\source\\red_role\\r34.png";
	m_shallow = cvLoadImage(file2, 1);
}
