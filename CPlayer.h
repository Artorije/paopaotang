#pragma once
#include"MMap.h"
#include"Shell.h"
#include<vector>
#include<iostream>
#include<time.h>
using namespace std;
#include<opencv2\opencv.hpp>
class CPlayer
{
public:
	CPlayer();
	~CPlayer();

public:
	bool m_move; /**< 判断玩家某时候是否具有移动的条件 */
	CvPoint m_pos;/**< 玩家像素点的位置 */
	int m_life;/**< 玩家的生命数 */
	int m_speed;/**< 玩家在地图中的移动速度 */
	int m_dir;/**< 玩家在某一个时候运动的方向 */
	int m_numfire;/**< 玩家自身含有的子弹数目 */
	int m_power;/**< 玩家自身炮弹的威力的大小 */
	IplImage** m_player;/**< 玩家图片信息的指针数组 */
	IplImage* m_shallow;/**< 玩家阴影的指针数组 */
	IplImage** m_ride;/**< 玩家坐骑的指针数组 */
	bool m_die;  /**< 判断玩家是否死亡 */
	int m_state;/**< 记录角色某一时刻在图片数组中显现的下标的位置 */
	int m_stateRide;
	vector<CShell*>m_shells;/** 玩家自身含有的炮弹的容器 */
	void DrawtoBK(IplImage* pbk);/**< 将玩家显现在数组上的功能函数 */
	void Move(int x);/**< 让玩家的实际位置根据给定的方向变换 */
	void SetImage(IplImage** pimg);/**< 从资源类里接受图片信息 */
	void ReleaseImg();/**< 释放自身所占有的内存 */
	void IsMove(int x, int y);/**< 判断玩家在某一时刻是否具有移动的条件 */
	int GetPositionX();/**< 返回当前玩家所在的位置的x轴 */
	int GetPositiony();/**< 返回当前玩家所在的位置的y轴 */
	int IsBoom();/**< 判断玩家是否具有放炸弹的条件 */
	void CreateBoom(IplImage** pimg, CShell* p);/**<创造一个相应的类并且生成相应的内存 */
	bool IsEmpty();/**< 判断是否还有炸弹没有爆炸 */
	void ShellGrow();/**< 玩家放的炸弹动态变换 */
	CShell* ShellBoom(IplImage* pbk);/**< 看未爆的炸弹是否具有爆炸的信息，有就返回相应的指针，没有就返回空 */
	int GetPow();/**< 获得玩家的炸弹威力信息 */
	void SuccessBoom(int x);/**<玩家炸爆炸或者放炸弹，负责收回炸弹 */
	void AllDrawBomm(IplImage* pbk, CShell* p, CMMap* map);/**< 绘制炸弹爆炸信息 */
	void SetPower();/**< 增加玩家炮弹的威力 */
	void SetNumfire();/**< 增加玩家释放炮弹的数量 */
	void SetSpeed();/**< 增加玩家自身移动速度 */
	virtual void InitPos(int x,int y) = 0;

	void SetShallowImage(IplImage* pimg);
	void SetPowerDouble();
	void MoveRide(int x);
};

