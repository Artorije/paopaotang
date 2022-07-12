#pragma once
#include<opencv2\opencv.hpp>
class CRide
{
public:
	CRide();
	~CRide();
	IplImage* m_player[4];
	IplImage* m_body[4];
	IplImage* m_append[2];
	virtual void LoadPlayer(int type) = 0;
	virtual void LoadBody(int type) = 0;
	virtual void LoadAppend(int type) = 0;
	virtual void SetImageBody(IplImage** body) = 0;
	virtual void SetImageAppend(IplImage** append) = 0;
	virtual void SetImagePlayer(IplImage** player) = 0;
};

