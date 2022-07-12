#include "CObserverJudgeHurt.h"

CObserverJudgeHurt::CObserverJudgeHurt(CShell * paodan, CPlayer* player1, CPlayer* player2, CMMap* map):CObserver(paodan,player1,player2,map)
{
}

CObserverJudgeHurt::~CObserverJudgeHurt()
{
}

void CObserverJudgeHurt::Action()
{
	int power = player1->m_power;
	int paodan_x = paodan->GetPositionx();
	int paodan_y = paodan->GetPositiony();
	int p1_x = player1->GetPositionX();
	int p1_y = player1->GetPositiony();
	int p2_x = player2->GetPositionX();
	int p2_y = player2->GetPositiony();

	int i;
	for (i = 0; i <= power; i++)
	{
		if (i > 0 && map->m_Map[paodan_x - i][paodan_y] != 0 || p1_y != paodan_y)
			break;
		if (paodan_x - i == p1_x) //上
		{
			player1->m_die = true;
			break;
		}
	}
	for (i = 0; i <= power; i++)
	{
		if (i > 0 && map->m_Map[paodan_x + i][paodan_y] != 0 || p1_y != paodan_y)
			break;
		if (paodan_x + i == p1_x)//下
		{
			player1->m_die = true;
			break;
		}
	}
	for (i = 0; i <= power; i++)
	{
		if (i > 0 && map->m_Map[paodan_x][paodan_y - i] != 0 || p1_x != paodan_x)
			break;
		if (paodan_y - i == p1_y)//左
		{
			player1->m_die = true;
			break;
		}
	}
	for (i = 0; i <= power; i++)
	{
		if (i > 0 && map->m_Map[paodan_x][paodan_y + i] != 0 || p1_x != paodan_x)
			break;
		if (paodan_y + i == p1_y)//右
		{
			player1->m_die = true;
			break;
		}
	}

	for (i = 0; i <= power; i++)
	{
		if (i > 0 && map->m_Map[paodan_x - i][paodan_y] != 0 || p2_y != paodan_y)
			break;
		if (paodan_x - i == p2_x) //上
		{
			player2->m_die = true;
			break;
		}
	}
	for (i = 0; i <= power; i++)
	{
		if (i > 0 && map->m_Map[paodan_x + i][paodan_y] != 0 || p2_y != paodan_y)
			break;
		if (paodan_x + i == p2_x)//下
		{
			player2->m_die = true;
			break;
		}
	}
	for (i = 0; i <= power; i++)
	{
		if (i > 0 && map->m_Map[paodan_x][paodan_y - i] != 0 || p2_x != paodan_x)
			break;
		if (paodan_y - i == p2_y)//左
		{
			player2->m_die = true;
			break;
		}
	}
	for (i = 0; i <= power; i++)
	{
		if (i > 0 && map->m_Map[paodan_x][paodan_y + i] != 0 || p2_x != paodan_x)
			break;
		if (paodan_y + i == p2_y)//右
		{
			player2->m_die = true;
			break;
		}
	}
}
