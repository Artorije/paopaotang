#include "CSisterSkin.h"

CSisterSkin::CSisterSkin()
{
}

CSisterSkin::~CSisterSkin()
{
}


void CSisterSkin::LoadImage()
{
	int i;
	char flie1[] = ".\\source\\sister_role\\s00.png";
	for (i = 0; i < 24; i++)
	{
		sprintf_s(flie1, ".\\source\\sister_role\\s%02d.png", i);
		m_skin[i] = cvLoadImage(flie1, 1);
	}
	char file2[] = ".\\source\\sister_role\\s34.png";
	m_shallow = cvLoadImage(file2, 1);

}
