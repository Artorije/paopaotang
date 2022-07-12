#include "GameEnergy.h"
#include"CObserverJudgeHurt.h"
#include"CShellStrategyBlue.h"
#include"CShellStrategyC.h"
#include"CShellStrategyZ.h"
#include"CShellStrategyBlack.h"
class CMMap;
CGameEnergy::CGameEnergy()
{
	m_state = 0;
}

CGameEnergy::~CGameEnergy()
{
}

void on_mouse(int event, int x, int y, int flags, void* param)
{
	CGameEnergy *game = (CGameEnergy *)param;
	switch (event)
	{
		case CV_EVENT_LBUTTONDOWN:
		{
			if (x > 135 && x < 336 && y>378 && y < 429)
			{
				game->m_state = 1;
			}
		}
	}
}

void CGameEnergy::InitGame()
{
	cvNamedWindow("122", 1);
	map1 = CMMap::GetInstance();
	map1->ReadTxtmappath();
	map1->AddBrick();
	map1->CreateBKimg();
	m_copy = cvCloneImage(map1->m_pBK);

	player_factory = new CPlayerFactory();
	skin_factory = new CSkinFactory();
	redbaby = player_factory->BuildRole(1);//创造第一个角色
	skin1 = skin_factory->Select(2);//选二号皮肤
	redbaby->SetImage(skin1->m_skin);
	redbaby->SetShallowImage(skin1->m_shallow);
	//redbaby->DrawtoBK(map1->m_pBK);

	pirate = player_factory->BuildRole(2);
	skin2 = skin_factory->Select(4);
	pirate->SetImage(skin2->m_skin);
	pirate->SetShallowImage(skin2->m_shallow);
	//pirate->DrawtoBK(map1->m_pBK);

	m_ridebuilder = new CRideBulider();
	m_ridebuilder->Construct(pirate);
	//m_ridebuilder->DrawtoBK(map1->m_pBK);
}

void CGameEnergy::Run()
{
	int c, x, y;
	int q, m, n;
//	PlaySound("BGM.wav", NULL, SND_NOSTOP | SND_ALIAS | SND_ASYNC);
	while (true)
	{
		if (m_state == 0)
		{
			cvSetMouseCallback("122", on_mouse, this);
			welcome = cvLoadImage(".\\source\\ss.png", 1);
			cvShowImage("122", welcome);
			cvWaitKey(0);
		}
		else
		{
			c = cvWaitKey(10);
			//q = cvWaitKey(10);
			//if (c == 27||q==27)
			//	break;
			x = GetDirector1(c);    //1 2 3 4 上下左右 0是炸弹
			//m = GetDirector2(q);
			if (x == 1 || x == 2 || x == 3 || x == 4)
			{
				y = LookMap1(x);
				redbaby->IsMove(x, y);
				redbaby->Move(x);
				IsPick1();
			}
			//if (m == 1 || m == 2 || m == 3 || m == 4)
			//{
			//	n = LookMap2(m);
			//	enemy1.IsMove(m, n);
			//	enemy1.Move(m);
			//	IsPick2();
			//}
			cvCopy(m_copy, map1->m_pBK);
			RelationBandT1(x);
			//RelationBandT2(m);
			redbaby->DrawtoBK(map1->m_pBK);
			//pirate->DrawtoBK(map1->m_pBK);
			m_ridebuilder->DrawtoBK(map1->m_pBK);
			cvShowImage("122", map1->m_pBK);
			Gameover();
		}
	}
}

void CGameEnergy::RelationBandT1(int x)
{
	if (x == 0 && redbaby->IsBoom() > 0)//放了一个炸弹
	{
		redbaby->SuccessBoom(-1);   //手中的炸弹减一颗
		int xx = redbaby->GetPositionX();
		int yy = redbaby->GetPositiony();
		srand((unsigned)time(0));
		int shelltype = rand() % 4;
		CShell* p = new CShell();
		switch (shelltype)
		{
		case 0:
			shellstrategy = new CShellStrategyBlue();
			break;
		case 1:
			shellstrategy = new CShellStrategyC();
			break;
		case 2:
			shellstrategy = new CShellStrategyZ();
			break;
		case 3:
			shellstrategy = new CShellStrategyBlack();
			break;
		default:
			break;
		}
		shellstrategy->LoadShellImage();
		redbaby->CreateBoom(shellstrategy->ShellImage,p);
		CObserverJudgeHurt* oj = new CObserverJudgeHurt(p,redbaby,pirate,map1);
		p->SetObserver(oj);
		observers.push_back(oj);

		map1->FixUp(xx, yy);
	}
	if (redbaby->IsEmpty() == true)   //存在炮弹
	{
		redbaby->ShellGrow();
		CShell* p = redbaby->ShellBoom(map1->m_pBK);
		if (p != NULL)  //容器里指定的元素要爆炸
		{
			redbaby->SuccessBoom(1);  //手中的炸弹家一颗
			int xx = p->GetPositionx();
			int yy = p->GetPositiony();//记录炸弹爆炸的位置
			int pow = redbaby->GetPow();
			//redbaby->IsDeath(xx, yy, &map1);
			map1->FixClear(xx, yy, pow);//清空地图上的元素
			map1->UpMap();
			cvCopy(map1->m_pBK, m_copy);//新地图复制给复制图层
			redbaby->AllDrawBomm(map1->m_pBK, p, map1);   //画特效
			vector<CObserver*>::iterator iter;
			for (iter = observers.begin(); iter < observers.end(); iter++)
			{
				if ((*iter) == (p->observer)) {
					observers.erase(iter);
					break;
				}
			}
			delete p;
		}
	}
}

void CGameEnergy::RelationBandT2(int x)
{
	if (x == 0 && pirate->IsBoom() > 0)//放了一个炸弹
	{
		pirate->SuccessBoom(-1);   //手中的炸弹减一颗
		int xx = pirate->GetPositionX();
		int yy = pirate->GetPositiony();
		srand((unsigned)time(0));
		int shelltype = rand() % 4;
		CShell* p = new CShell();
		switch (shelltype)
		{
		case 0:
			shellstrategy = new CShellStrategyBlue();
			break;
		case 1:
			shellstrategy = new CShellStrategyC();
			break;
		case 2:
			shellstrategy = new CShellStrategyZ();
			break;
		case 3:
			shellstrategy = new CShellStrategyBlack();
			break;
		default:
			break;
		}
		shellstrategy->LoadShellImage();
		pirate->CreateBoom(shellstrategy->ShellImage, p);
		CObserverJudgeHurt* oj = new CObserverJudgeHurt(p, redbaby, pirate, map1);
		p->SetObserver(oj);
		observers.push_back(oj);

		map1->FixUp(xx, yy);
	}
	if (pirate->IsEmpty() == true)   //存在炮弹
	{
		pirate->ShellGrow();
		CShell* p = pirate->ShellBoom(map1->m_pBK);
		if (p != NULL)  //容器里指定的元素要爆炸
		{
			pirate->SuccessBoom(1);  //手中的炸弹家一颗
			int xx = p->GetPositionx();
			int yy = p->GetPositiony();//记录炸弹爆炸的位置
			int pow = pirate->GetPow();
			map1->FixClear(xx, yy, pow);//清空地图上的元素
			map1->UpMap();
			cvCopy(map1->m_pBK, m_copy);//新地图复制给复制图层
			pirate->AllDrawBomm(map1->m_pBK, p, map1);   //画特效
			vector<CObserver*>::iterator iter;
			for (iter = observers.begin(); iter < observers.end(); iter++)
			{
				if ((*iter) == (p->observer)) {
					observers.erase(iter);
					break;
				}
			}
			delete p;
		}
	}
}

void CGameEnergy::Releaseimg()
{
	int i;
	map1->Release();
	redbaby->ReleaseImg();
	pirate->ReleaseImg();
	cvReleaseImage(&m_copy);
}

int CGameEnergy::GetDirector1(int x)
{
	if (x == 'W' || x == 'w'||x=='↑')
	{
		return 1;
	}
	if (x == 'S' || x == 's'||x=='↓')
	{
		return 2;
	}
	if (x == 'a' || x == 'A'||x=='←')
	{
		return 3;
	}
	if (x == 'd' || x == 'D'||x=='→')
	{
		return 4;
	}
	if(x==' ')
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

int CGameEnergy::GetDirector2(int x)
{
	if (x == '8')
	{
		return 1;
	}
	if (x == '5')
	{
		return 2;
	}
	if (x == '4')
	{
		return 3;
	}
	if (x == '6')
	{
		return 4;
	}
	if (x == '0')
	{
		return 5;
	}
	else
	{
		return -1;
	}
}

int CGameEnergy::LookMap1(int x)
{
	int aa, bb;
	aa = redbaby->GetPositionX();
	bb = redbaby->GetPositiony();
	if (x == 1&&aa-1>=0)
	{
		return map1->m_Map[aa-1][bb];
	}
	else if (x == 2&&aa+1<15)
	{
		return map1->m_Map[aa+1][bb];
	}
	else if (x == 3&&bb-1>=0)
	{
		return map1->m_Map[aa][bb-1];
	}
	else if (x == 4&&bb+1<16)
	{
		return map1->m_Map[aa][bb+1];
	}
	else
	{
		return 1;
	}
}

int CGameEnergy::LookMap2(int x)
{
	int aa, bb;
	aa = pirate->GetPositionX();
	bb = pirate->GetPositiony();
	if (x == 1 && aa - 1 >= 0)
	{
		return map1->m_Map[aa - 1][bb];
	}
	else if (x == 2 && aa + 1<15)
	{
		return map1->m_Map[aa + 1][bb];
	}
	else if (x == 3 && bb - 1 >= 0)
	{
		return map1->m_Map[aa][bb - 1];
	}
	else if (x == 4 && bb + 1<16)
	{
		return map1->m_Map[aa][bb + 1];
	}
	else
	{
		return 1;
	}
}

void CGameEnergy::IsPick1()
{
	int xx = redbaby->GetPositionX();
	int yy = redbaby->GetPositiony();
	if (map1->m_Map[xx][yy] == 11 || map1->m_Map[xx][yy] == 12 || map1->m_Map[xx][yy] == 13 || map1->m_Map[xx][yy] == 24)
	{
		if (map1->m_Map[xx][yy] == 11)
			redbaby->SetNumfire();
		else if (map1->m_Map[xx][yy] == 12)
			redbaby->SetPower();
		else if (map1->m_Map[xx][yy] == 24)
			redbaby->SetPowerDouble();
		else if (map1->m_Map[xx][yy] == 13)
			redbaby->SetSpeed();
		map1->m_Map[xx][yy] = 0;
		map1->Delet_Tools(xx, yy);
		map1->UpMap();
		cvCopy(map1->m_pBK, m_copy);
	}
}

void CGameEnergy::IsPick2()
{
	int xx = pirate->GetPositionX();
	int yy = pirate->GetPositiony();
	if (map1->m_Map[xx][yy] == 11 || map1->m_Map[xx][yy] == 12 || map1->m_Map[xx][yy] == 13)
	{
		if (map1->m_Map[xx][yy] == 11)
			pirate->SetNumfire();
		if (map1->m_Map[xx][yy] == 12)
			pirate->SetPower();
		if (map1->m_Map[xx][yy] == 13)
			pirate->SetSpeed();
		map1->m_Map[xx][yy] = 0;
		map1->UpMap();
		cvCopy(map1->m_pBK, m_copy);
	}
}

void CGameEnergy::Gameover()
{
	if (redbaby->m_die == true)
	{
		cout << "玩家1 game over!" << endl;
		IplImage *pimg;
		pimg = cvLoadImage(".\\source\\结束界面2.png");
		cvShowImage("122", pimg);
		cvWaitKey(0);
		exit(0);
	}
	if (pirate->m_die == true)
	{
		cout << "玩家2 game over!" << endl;
		IplImage *pimg;
		pimg = cvLoadImage(".\\source\\结束界面1.png");
		cvShowImage("122", pimg);
		cvWaitKey(0);
		exit(0);
	}
}
