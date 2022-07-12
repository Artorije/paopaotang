#include "CPlayer.h"


CPlayer::CPlayer()
{
	m_die = false;
	m_move = false;
	m_state = 6;
	m_life = 3;
	m_speed = 1;
	m_numfire = 1;
	m_power = 1;
	m_stateRide = 0;
	cout << "工厂创建了基角色" << endl;
}

CPlayer::~CPlayer()
{
}

void CPlayer::DrawtoBK(IplImage* pbk)
{
	vector<CShell*>::iterator iter;
	for (iter = m_shells.begin(); iter < m_shells.end(); iter++)
	{
		(*iter)->DrawtoBK(pbk);
	}

	//画阴影
	if (pbk != NULL && m_shallow != NULL)
	{
		for (int i = 0; i < m_shallow->height; i++)
		{
			for (int j = 0; j < m_shallow->width; j++)
			{
				int bv = CV_IMAGE_ELEM(m_shallow, uchar, i, j * 3 + 0);
				int gv = CV_IMAGE_ELEM(m_shallow, uchar, i, j * 3 + 1);
				int rv = CV_IMAGE_ELEM(m_shallow, uchar, i, j * 3 + 2);
				if (!(bv == 0 && gv == 0 && rv == 0))
				{
					int x, y;
					x = m_pos.y - m_shallow->width / 2 + 32 / 2;
					y = m_pos.x + 3 * 32 / 4;
					if (!(j + x < 0 || j + x>16 * 32 || y + i < 0 || y + i>15 * 32))
					{
						CV_IMAGE_ELEM(pbk, uchar, y + i, (x + j) * 3 + 0) =
							CV_IMAGE_ELEM(m_shallow, uchar, i, j * 3 + 0);
						CV_IMAGE_ELEM(pbk, uchar, y + i, (x + j) * 3 + 1) =
							CV_IMAGE_ELEM(m_shallow, uchar, i, j * 3 + 1);
						CV_IMAGE_ELEM(pbk, uchar, y + i, (x + j) * 3 + 2) =
							CV_IMAGE_ELEM(m_shallow, uchar, i, j * 3 + 2);
					}
				}
			}
		}
	}
	//画人
	if (pbk != NULL && m_player[m_state] != NULL)
	{
		for (int i = 0; i < m_player[m_state]->height; i++)
		{
			for (int j = 0; j < m_player[m_state]->width; j++)
			{
				int bv = CV_IMAGE_ELEM(m_player[m_state], uchar, i, j * 3 + 0);
				int gv = CV_IMAGE_ELEM(m_player[m_state], uchar, i, j * 3 + 1);
				int rv = CV_IMAGE_ELEM(m_player[m_state], uchar, i, j * 3 + 2);
				if (!(bv == 0 && gv == 0 && rv == 0))
				{
					int x, y;
					x = m_pos.y - m_player[m_state]->width / 2 + 32 / 2;
					y = m_pos.x - m_player[m_state]->height + 32;
					if (!(j + x < 0 || j + x>16 * 32 || y + i < 0 || y + i>15 * 32))
					{
						CV_IMAGE_ELEM(pbk, uchar, y + i, (x + j) * 3 + 0) =
							CV_IMAGE_ELEM(m_player[m_state], uchar, i, j * 3 + 0);
						CV_IMAGE_ELEM(pbk, uchar, y + i, (x + j) * 3 + 1) =
							CV_IMAGE_ELEM(m_player[m_state], uchar, i, j * 3 + 1);
						CV_IMAGE_ELEM(pbk, uchar, y + i, (x + j) * 3 + 2) =
							CV_IMAGE_ELEM(m_player[m_state], uchar, i, j * 3 + 2);
					}
				}
			}
		}
	}
}

void CPlayer::Move(int x)
{
	int nowdir = m_state;
	if (x == 1) //上
	{
		if (m_pos.x - 32 >= 0 && m_move == true)
		{
			m_pos.x -= 32;
			m_move = false;
		}
		if (m_state > 5)   //变方向
		{
			m_state = 0;
		}
		else
		{
			m_state++;
		}
		if (m_state > 5)
			m_state = 0;
	}
	else if (x == 2)//下
	{
		if (m_pos.x + 32 < 15 * 32 && m_move == true)
		{
			m_pos.x += 32;
			m_move = false;
		}
		if (m_state < 6 || m_state > 11)
		{
			m_state = 6;
		}
		else
		{
			m_state++;
		}
		if (m_state > 11)
			m_state = 6;

	}
	else if (x == 3)//左
	{
		if (m_pos.y - 32 >= 0 && m_move == true)
		{
			m_pos.y -= 32;
			m_move = false;
		}
		if (nowdir < 12 || nowdir>17)
		{
			m_state = 12;
		}
		else
		{
			m_state++;
		}
		if (m_state > 17)
		{
			m_state = 12;
		}
	}
	else if (x == 4)//右
	{
		if (m_pos.y + 32 < 16 * 32 && m_move == true)
		{
			m_pos.y += 32;
			m_move = false;
		}
		if (nowdir < 18)
		{
			m_state = 18;
		}
		else
		{
			m_state++;
		}
		if (m_state > 23)
		{
			m_state = 18;
		}
	}

}

void CPlayer::MoveRide(int x)
{
	int nowdir = m_stateRide;
	if (x == 1) //上
	{
		if (m_pos.x - 32 >= 0 && m_move == true)
		{
			m_pos.x -= 32;
			m_move = false;
		}
		m_stateRide = 1;
	}
	else if (x == 2)//下
	{
		if (m_pos.x + 32 < 15 * 32 && m_move == true)
		{
			m_pos.x += 32;
			m_move = false;
		}
		m_stateRide = 0;

	}
	else if (x == 3)//左
	{
		if (m_pos.y - 32 >= 0 && m_move == true)
		{
			m_pos.y -= 32;
			m_move = false;
		}
		m_stateRide = 2;
	}
	else if (x == 4)//右
	{
		if (m_pos.y + 32 < 16 * 32 && m_move == true)
		{
			m_pos.y += 32;
			m_move = false;
		}
		m_stateRide = 3;
	}
}


void CPlayer::SetImage(IplImage** pimg)
{
	m_player = pimg;
}

void CPlayer::SetShallowImage(IplImage* pimg)
{
	m_shallow = pimg;
}

void CPlayer::ReleaseImg()
{
	for (int i = 0; i < 24; i++)
	{
		cvReleaseImage(&m_player[i]);
	}
}

void CPlayer::IsMove(int x, int y)
{

	if (x == 1)
	{
		if (m_pos.x > 0 && (y == 0 || y == 11 || y == 12 || y == 13 || y==24))
		{
			m_move = true;
		}
	}
	else if (x == 2)
	{
		if (m_pos.x < 15 * 32 && (y == 0 || y == 11 || y == 12 || y == 13 || y==24))
		{
			m_move = true;
		}
	}
	else if (x == 3)
	{
		if (m_pos.y > 0 && (y == 0 || y == 11 || y == 12 || y == 13 || y==24))
		{
			m_move = true;
		}
	}
	else if (x == 4)
	{
		if (m_pos.y < 16 * 32 && (y == 0 || y == 11 || y == 12 || y == 13 || y==24))
		{
			m_move = true;
		}
	}
}

int CPlayer::GetPositionX()
{
	return m_pos.x / 32;
}

int CPlayer::GetPositiony()
{
	return m_pos.y / 32;
}

int CPlayer::IsBoom()
{
	if (m_numfire == 0)
		return 0;
	return 1;
}

void CPlayer::CreateBoom(IplImage** pimg,CShell* p)
{
	p->m_pos.x = m_pos.x;
	p->m_pos.y = m_pos.y;
	p->SetImage(pimg);
	m_shells.push_back(p);
}

bool CPlayer::IsEmpty()
{
	if (m_shells.empty())
	{
		return false;
	}
	return true;
}

void CPlayer::ShellGrow()
{
	vector<CShell*>::iterator iter;
	for (iter = m_shells.begin(); iter < m_shells.end(); iter++)
	{
		//cvWaitKey(50);
		(*iter)->ChangeShep();
	}
}

CShell* CPlayer::ShellBoom(IplImage* pbk)
{
	vector<CShell*>::iterator iter;
	for (iter = m_shells.begin(); iter != m_shells.end();iter++)
	{
		if ((*iter)->Boom() == true)
		{
			CShell* p = *iter;
			// delete *iter;
			 //AllDrawBomm(pbk, *iter);
			iter = m_shells.erase(iter);
			return p;
		}
	}
	return NULL;
}

int CPlayer::GetPow()
{
	return m_power;
}

void CPlayer::SuccessBoom(int x)
{
	m_numfire += x;
}

void CPlayer::AllDrawBomm(IplImage* pbk, CShell* p, CMMap* map)
{
	int i;
	int xx = p->GetPositionx();
	int yy = p->GetPositiony(); //炸弹当前的数量
	for (i = 1; i <= m_power; i++)
	{
		if (map->m_Map[xx - i][yy] > 3)
			break;
		if (map->m_Map[xx - i][yy] >= 0)
		{
			p->DraeEffects(pbk, xx - i, yy, 4);
			if (map->m_Map[xx - i][yy] > 0)
				break;
		}
	}
	for (i = 1; i <= m_power; i++)
	{
		if (map->m_Map[xx + i][yy] > 3)
			break;
		if (map->m_Map[xx + i][yy] >= 0)
		{
			p->DraeEffects(pbk, xx + i, yy, 5);
			if (map->m_Map[xx + i][yy] > 0)
				break;
		}
	}
	for (i = 1; i <= m_power; i++)
	{
		if (map->m_Map[xx][yy - i] > 3)
			break;
		if (map->m_Map[xx][yy - i] >= 0)
		{
			p->DraeEffects(pbk, xx, yy - i, 6);
			if (map->m_Map[xx][yy - i] > 0)
				break;
		}
	}
	for (i = 1; i <= m_power; i++)
	{
		if (map->m_Map[xx][yy + i] > 3)
			break;
		if (map->m_Map[xx][yy + i] >= 0)
		{
			p->DraeEffects(pbk, xx, yy + i, 7);
			if (map->m_Map[xx][yy + i] > 0)
				break;
		}
	}
}

void CPlayer::SetPower()
{
	m_power++;
}

void CPlayer::SetPowerDouble()
{
	m_power = +2;
}

void CPlayer::SetNumfire()
{
	m_numfire++;
}

void CPlayer::SetSpeed()
{
	m_speed++;
}

