#include "CRideBulider.h"

CRideBulider::CRideBulider()
{
}

CRideBulider::~CRideBulider()
{
}


CRide* CRideBulider::Construct(CPlayer* player)
{
    ride = new CRideUFO();
    ride->LoadPlayer(4);
    ride->LoadBody(4);
    ride->LoadAppend(4);
	SetPlayer(player);
    return ride;
}


void CRideBulider::SetPlayer(CPlayer* player)
{
    player_builder = player;
}


void CRideBulider::DrawtoBK(IplImage* pbk)
{
	//»­ÈË
	if (pbk != NULL && ride->m_player[0] != NULL)
	{
		for (int i = 0; i < ride->m_player[0]->height; i++)
		{
			for (int j = 0; j < ride->m_player[0]->width; j++)
			{
				int bv = CV_IMAGE_ELEM(ride->m_player[0], uchar, i, j * 3 + 0);
				int gv = CV_IMAGE_ELEM(ride->m_player[0], uchar, i, j * 3 + 1);
				int rv = CV_IMAGE_ELEM(ride->m_player[0], uchar, i, j * 3 + 2);
				if (!(bv == 0 && gv == 0 && rv == 0))
				{
					int x, y;
					//y = m_pos.x + 3 * 32 / 4;
					x = player_builder->m_pos.y - ride->m_player[0]->width / 2 + 32 / 2;
					//y = player_builder->m_pos.x - ride->m_player[player_builder->m_stateRide]->height + 32;
					y = player_builder->m_pos.x - 3 * 32 / 4;
					if (!(j + x < 0 || j + x>16 * 32 || y + i < 0 || y + i>15 * 32))
					{
						CV_IMAGE_ELEM(pbk, uchar, y + i, (x + j) * 3 + 0) =
							CV_IMAGE_ELEM(ride->m_player[0], uchar, i, j * 3 + 0);
						CV_IMAGE_ELEM(pbk, uchar, y + i, (x + j) * 3 + 1) =
							CV_IMAGE_ELEM(ride->m_player[0], uchar, i, j * 3 + 1);
						CV_IMAGE_ELEM(pbk, uchar, y + i, (x + j) * 3 + 2) =
							CV_IMAGE_ELEM(ride->m_player[0], uchar, i, j * 3 + 2);
					}
				}
			}
		}
	}
	//»­×øÆï
	if (pbk != NULL && ride->m_body[0] != NULL)
	{
		for (int i = 0; i < ride->m_body[0]->height; i++)
		{
			for (int j = 0; j < ride->m_body[0]->width; j++)
			{
				int bv = CV_IMAGE_ELEM(ride->m_body[0], uchar, i, j * 3 + 0);
				int gv = CV_IMAGE_ELEM(ride->m_body[0], uchar, i, j * 3 + 1);
				int rv = CV_IMAGE_ELEM(ride->m_body[0], uchar, i, j * 3 + 2);
				if (!(bv == 0 && gv == 0 && rv == 0))
				{
					int x, y;
					x = player_builder->m_pos.y - ride->m_body[0]->width / 2 + 32 / 2;
					y = player_builder->m_pos.x - ride->m_body[0]->height + 32;
					if (!(j + x < 0 || j + x>16 * 32 || y + i < 0 || y + i>15 * 32))
					{
						CV_IMAGE_ELEM(pbk, uchar, y + i, (x + j) * 3 + 0) =
							CV_IMAGE_ELEM(ride->m_body[0], uchar, i, j * 3 + 0);
						CV_IMAGE_ELEM(pbk, uchar, y + i, (x + j) * 3 + 1) =
							CV_IMAGE_ELEM(ride->m_body[0], uchar, i, j * 3 + 1);
						CV_IMAGE_ELEM(pbk, uchar, y + i, (x + j) * 3 + 2) =
							CV_IMAGE_ELEM(ride->m_body[0], uchar, i, j * 3 + 2);
					}
				}
			}
		}
	}
}
