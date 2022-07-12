#pragma once
#include<fstream>
#include<string.h>
#include<stdio.h>
#include<opencv2\opencv.hpp>
using namespace std;
class CSkin
{
public:
	CSkin();
	~CSkin();
	IplImage* m_skin[24];
	IplImage* m_shallow;
	virtual void LoadImage() = 0;
};

