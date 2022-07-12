#pragma once
#include<opencv2\opencv.hpp>
class CTool
{
public:
	CTool();
	~CTool();
	IplImage* tool_image;
	int posx, posy;
	virtual void LoadImage() = 0;
	virtual void InitPos(int x, int y) = 0;
};

