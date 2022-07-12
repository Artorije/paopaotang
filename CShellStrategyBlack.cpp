#include "CShellStrategyBlack.h"

CShellStrategyBlack::CShellStrategyBlack()
{
}

CShellStrategyBlack::~CShellStrategyBlack()
{
}


void CShellStrategyBlack::LoadShellImage()
{
	int i;
	char flie1[] = ".\\source\\shell\\k00.png";
	for (i = 0; i < 4; i++)//ÅÚµ¯
	{
		sprintf_s(flie1, ".\\source\\shell\\k%02d.png", i);
		ShellImage[i] = cvLoadImage(flie1, 1);
	}
	for (i = 4; i < 8; i++)//ÅÚµ¯
	{
		sprintf_s(flie1, ".\\source\\shell\\%d.png", i);
		ShellImage[i] = cvLoadImage(flie1, 1);
	}

}
