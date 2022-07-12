#include "CRideUFO.h"

CRideUFO::CRideUFO()
{
}

CRideUFO::~CRideUFO()
{
}

void CRideUFO::LoadPlayer(int type)
{
		int i;
		char flie1[] = ".\\source\\green_role\\ride0.png";
		for (i = 0; i < 4; i++)
		{
			sprintf_s(flie1, ".\\source\\green_role\\ride%d.png", i);
			m_player[i] = cvLoadImage(flie1, 1);
		}
		//SetImagePlayer(player);

}

void CRideUFO::LoadBody(int type)
{
		//IplImage* body[4];
		int i;
		char flie1[] = ".\\source\\green_role\\rUFO0.png";
		for (i = 0; i < 4; i++)
		{
			sprintf_s(flie1, ".\\source\\green_role\\rUFO%d.png", i);
			m_body[i] = cvLoadImage(flie1, 1);
		}
		//SetImageBody(body);
}

void CRideUFO::LoadAppend(int type)
{
		//IplImage * append[2];
		int i;
		char flie1[] = ".\\source\\green_role\\rAppend0.png";
		for (i = 1; i < 2; i++)
		{
			sprintf_s(flie1, ".\\source\\green_role\\rAppend%d.png", i);
			m_append[i] = cvLoadImage(flie1, 1);
		}
		//SetImageAppend(append);
}

void CRideUFO::SetImagePlayer(IplImage** player)
{
	//m_player = player;
}

void CRideUFO::SetImageBody(IplImage** body)
{
	//m_body = body;
}

void CRideUFO::SetImageAppend(IplImage** append)
{
	//m_append = append;
}

