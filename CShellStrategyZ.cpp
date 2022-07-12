#include "CShellStrategyZ.h"

CShellStrategyZ::CShellStrategyZ()
{
}

CShellStrategyZ::~CShellStrategyZ()
{
}


void CShellStrategyZ::LoadShellImage()
{
	int i;
	char flie1[] = ".\\source\\shell\\z00.png";
	for (i = 0; i < 4; i++)//ÅÚµ¯
	{
		sprintf_s(flie1, ".\\source\\shell\\z%02d.png", i);
		ShellImage[i] = cvLoadImage(flie1, 1);
	}
	for (i = 4; i < 8; i++)//ÅÚµ¯
	{
		sprintf_s(flie1, ".\\source\\shell\\%d.png", i);
		ShellImage[i] = cvLoadImage(flie1, 1);
	}
}
