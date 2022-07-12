#include "CGreenSkin.h"

CGreenSkin::CGreenSkin()
{
}

CGreenSkin::~CGreenSkin()
{
}


void CGreenSkin::LoadImage()
{
	int i;
	char flie1[] = ".\\source\\green_role\\g00.png";
	for (i = 0; i < 24; i++)
	{
		sprintf_s(flie1, ".\\source\\green_role\\g%02d.png", i);
		m_skin[i] = cvLoadImage(flie1, 1);
	}

	char file2[] = ".\\source\\green_role\\g34.png";
	m_shallow = cvLoadImage(file2, 1);
}
