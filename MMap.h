/**
* @class CMMap
* @brief ��Ϸ�ĵ�ͼ��
*
*CMMap����Ϸ�еĵ�ͼ�࣬�����˼��س���ͼƬ���ص�ͼ��Ϣ�Ĺ���
*/
#pragma once
#include<stdlib.h>
#include<opencv.hpp>
#include<opencv\highgui.h>
#include<fstream>
#include<iostream>
#include<opencv2\opencv.hpp>
#include"CBrick.h"
#include"CTool.h"
#include"CToolShell.h"
#include"CToolPower.h"
#include"CToolShoe.h"
#include"CToolDecorator.h"
#include"CToolDecoratorPurplePotion.h"
using namespace std;

class CMMap
{
public:
	~CMMap();
	int choose;
	int m_Map[15][16];  /**< ��ͼ���� */
	IplImage *m_pBK;    /**< ���ر���ͼƬ��ָ�� */
	IplImage **m_tools;/**< ���ع��ߵ�ָ�� */
	CBrick* bricks[15][16];/**<���س�����ָ�� */
	IplImage* m_paththings[15];/**<���� */
	vector<CTool*>tools;

//	void InitImage(); /**< ���ⲿ���ص�ͼ����Ϣ */
	void ReadTxtmappath();/**< �����ȡ�������Ϣ */
	void CreateBKimg();/**<��汳�� */
	void Release();/**< �ͷ���Ϣ */
	void FixUp(int x, int y);/**< ����ͷ�ը����λ�� */
	void FixClear(int x, int y,int pow);/**< ը����ը������� */
	void SetTool(IplImage ** pimg);/**< ���ع���ͼƬ */
	void UpMap();/**< ���»��Ƶ�ͼ */
	void AddBrick();
	void Delet_Tools(int x, int y);
	static CMMap* GetInstance();
private:
	static CMMap* _instance;
	CMMap();
};
