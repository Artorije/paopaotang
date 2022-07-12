/**
* @class CMMap
* @brief 游戏的地图类
*
*CMMap是游戏中的地图类，包含了加载场景图片返回地图信息的功能
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
	int m_Map[15][16];  /**< 地图数组 */
	IplImage *m_pBK;    /**< 加载背景图片的指针 */
	IplImage **m_tools;/**< 加载工具的指针 */
	CBrick* bricks[15][16];/**<加载场景的指针 */
	IplImage* m_paththings[15];/**<暂留 */
	vector<CTool*>tools;

//	void InitImage(); /**< 从外部加载地图的信息 */
	void ReadTxtmappath();/**< 从外读取数组的信息 */
	void CreateBKimg();/**<描绘背景 */
	void Release();/**< 释放信息 */
	void FixUp(int x, int y);/**< 标记释放炸弹的位置 */
	void FixClear(int x, int y,int pow);/**< 炸弹爆炸清空数组 */
	void SetTool(IplImage ** pimg);/**< 加载工具图片 */
	void UpMap();/**< 重新绘制地图 */
	void AddBrick();
	void Delet_Tools(int x, int y);
	static CMMap* GetInstance();
private:
	static CMMap* _instance;
	CMMap();
};
