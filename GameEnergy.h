/**
* @class CGameEnergy
* @brief ��Ϸ������
*
*CGameEnergy����Ϸ������������࣬�����˳�ʼ�������У��ͷŵȲ���
*/
#include<time.h>
#pragma comment(lib,"winmm.lib")
#pragma once
#include "CRideBulider.h"
#include "MMap.h"
#include "Shell.h"
#include "AbstractRoleFactory.h"
#include "CPlayerFactory.h"
#include "CSkinFactory.h"
#include "CPlayer.h"
#include "CSkin.h"
#include "CObserver.h"
#include "CShellStrategy.h"
#include<opencv2\opencv.hpp>
#include<windows.h>
class CGameEnergy
{
public:
	CGameEnergy();
	~CGameEnergy();
	CRideBulider* m_ridebuilder;
	CMMap* map1;
	IplImage *m_copy;
	CPlayer* redbaby;
	CSkin* skin1;
	CPlayer* pirate;
	CSkin* skin2;
	AbstractRoleFactory* player_factory;
	AbstractRoleFactory* skin_factory;
	vector<CObserver*>observers;
	CShellStrategy* shellstrategy;
	IplImage* welcome;/**< ���ػ�ӭ���� */

	void Run();/**<��ͼ����ɫ ը�����໥�����Լ�Ӱ��  */
	void InitGame();/**<������Դ��ʼ����ͼ�����͸��������Ϣ  */
	void Releaseimg();/**< �ͷŵ����������Ϣ */
	int GetDirector1(int x);/**< �Ӽ��̻�ȡ������Ϣ���д�����ת�� */
	int GetDirector2(int x);
	int LookMap1(int x);/**< ���ص�ͼ�ǵ�ָ��λ�õ�λ����Ϣ */
	int LookMap2(int x);
	void RelationBandT1(int x);/**< �������������ڵ��Ĺ�ϵ */
	void RelationBandT2(int x);
	void IsPick1();/**< �������ߵĹ��� */
	void IsPick2();
	int m_state;/**< ����¼�����Ҫ���±� */
	void Gameover();/**< ʤ���жϺ��� */
};

