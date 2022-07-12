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
	bool m_move; /**< �ж����ĳʱ���Ƿ�����ƶ������� */
	CvPoint m_pos;/**< ������ص��λ�� */
	int m_life;/**< ��ҵ������� */
	int m_speed;/**< ����ڵ�ͼ�е��ƶ��ٶ� */
	int m_dir;/**< �����ĳһ��ʱ���˶��ķ��� */
	int m_numfire;/**< ��������е��ӵ���Ŀ */
	int m_power;/**< ��������ڵ��������Ĵ�С */
	IplImage** m_player;/**< ���ͼƬ��Ϣ��ָ������ */
	IplImage* m_shallow;/**< �����Ӱ��ָ������ */
	IplImage** m_ride;/**< ��������ָ������ */
	bool m_die;  /**< �ж�����Ƿ����� */
	int m_state;/**< ��¼��ɫĳһʱ����ͼƬ���������ֵ��±��λ�� */
	int m_stateRide;
	vector<CShell*>m_shells;/** ��������е��ڵ������� */
	void DrawtoBK(IplImage* pbk);/**< ����������������ϵĹ��ܺ��� */
	void Move(int x);/**< ����ҵ�ʵ��λ�ø��ݸ����ķ���任 */
	void SetImage(IplImage** pimg);/**< ����Դ�������ͼƬ��Ϣ */
	void ReleaseImg();/**< �ͷ�������ռ�е��ڴ� */
	void IsMove(int x, int y);/**< �ж������ĳһʱ���Ƿ�����ƶ������� */
	int GetPositionX();/**< ���ص�ǰ������ڵ�λ�õ�x�� */
	int GetPositiony();/**< ���ص�ǰ������ڵ�λ�õ�y�� */
	int IsBoom();/**< �ж�����Ƿ���з�ը�������� */
	void CreateBoom(IplImage** pimg, CShell* p);/**<����һ����Ӧ���ಢ��������Ӧ���ڴ� */
	bool IsEmpty();/**< �ж��Ƿ���ը��û�б�ը */
	void ShellGrow();/**< ��ҷŵ�ը����̬�任 */
	CShell* ShellBoom(IplImage* pbk);/**< ��δ����ը���Ƿ���б�ը����Ϣ���оͷ�����Ӧ��ָ�룬û�оͷ��ؿ� */
	int GetPow();/**< �����ҵ�ը��������Ϣ */
	void SuccessBoom(int x);/**<���ը��ը���߷�ը���������ջ�ը�� */
	void AllDrawBomm(IplImage* pbk, CShell* p, CMMap* map);/**< ����ը����ը��Ϣ */
	void SetPower();/**< ��������ڵ������� */
	void SetNumfire();/**< ��������ͷ��ڵ������� */
	void SetSpeed();/**< ������������ƶ��ٶ� */
	virtual void InitPos(int x,int y) = 0;

	void SetShallowImage(IplImage* pimg);
	void SetPowerDouble();
	void MoveRide(int x);
};

