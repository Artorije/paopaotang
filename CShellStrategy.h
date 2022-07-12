#pragma once
#include<opencv2\opencv.hpp>
class CShellStrategy
{
public:
	CShellStrategy();
	~CShellStrategy();
	IplImage* ShellImage[8];

	virtual void LoadShellImage() = 0;
};

