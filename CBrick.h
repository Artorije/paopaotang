#pragma once
#include<opencv2\opencv.hpp>
#include<vector>
using namespace std;
class CBrick
{
public:
	CBrick();
	~CBrick();
	IplImage* brick_image;
	vector<CBrick*> subordinates;
	void AddBrick(CBrick* b);
	void FixBrick(IplImage* pimg);
};