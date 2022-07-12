/**
* @class CGameEnergy
* @brief 游戏引擎类
*
*CGameEnergy是游戏驱动各个类的类，包含了初始化，运行，释放等操作
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
	IplImage* welcome;/**< 加载欢迎界面 */

	void Run();/**<地图，角色 炸弹的相互调用以及影响  */
	void InitGame();/**<加载资源初始化地图，传送各个类的信息  */
	void Releaseimg();/**< 释放掉所有类的信息 */
	int GetDirector1(int x);/**< 从键盘获取到的信息进行处理再转出 */
	int GetDirector2(int x);
	int LookMap1(int x);/**< 返回地图是的指定位置的位置信息 */
	int LookMap2(int x);
	void RelationBandT1(int x);/**< 负责调节人物和炮弹的关系 */
	void RelationBandT2(int x);
	void IsPick1();/**< 负责捡道具的功能 */
	void IsPick2();
	int m_state;/**< 鼠标事件所需要的下标 */
	void Gameover();/**< 胜负判断函数 */
};

