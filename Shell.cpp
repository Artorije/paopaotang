#include "Shell.h"
#include"CObserver.h"
#include"CObserverJudgeHurt.h"

CShell::CShell()
{
	m_state = 0;
	start = clock();
}


CShell::~CShell()
{
}


void CShell::SetImage(IplImage ** pimg)
{
	m_picture = pimg;
}


void CShell::ReleaseImg()
{
	for (int i = 0; i < 8; i++)
	{
		cvReleaseImage(&m_picture[i]);
	}
}


void CShell::DrawtoBK(IplImage *pbk)
{
	if (pbk != NULL && m_picture[m_state] != NULL)
	{
		for (int i = 0; i <m_picture[m_state]->height; i++)
		{
			for (int j = 0; j < m_picture[m_state]->width; j++)
			{
				int bv = CV_IMAGE_ELEM(m_picture[m_state], uchar, i, j * 3 + 0);
				int gv = CV_IMAGE_ELEM(m_picture[m_state], uchar, i, j * 3 + 1);
				int rv = CV_IMAGE_ELEM(m_picture[m_state], uchar, i, j * 3 + 2);
				if (!(bv == 0 && gv == 0 && rv == 0))
				{
					int x, y;
					x = m_pos.y - m_picture[m_state]->width / 2 + 32 / 2;
					y = m_pos.x - m_picture[m_state]->height + 32;
					if (!(j + x < 0 || j + x >= 16 * 32 || y + i < 0 || y + i >= 16 * 32))
					{
						CV_IMAGE_ELEM(pbk, uchar, y + i, (x + j) * 3 + 0) = 
							CV_IMAGE_ELEM(m_picture[m_state], uchar, i, j * 3 + 0);
						CV_IMAGE_ELEM(pbk, uchar, y + i, (x + j) * 3 + 1) = 
							CV_IMAGE_ELEM(m_picture[m_state], uchar, i, j * 3 + 1);
						CV_IMAGE_ELEM(pbk, uchar, y + i, (x + j) * 3 + 2) = 
							CV_IMAGE_ELEM(m_picture[m_state], uchar, i, j * 3 + 2);
					}
				}
			}
		}
	}
}


void CShell::ChangeShep()
{
	m_state++;
	if (m_state > 3)
	{
		m_state = 0;
	}
}

bool CShell::Boom()
{
	end = clock();
	if (end- start>=1500)
	{
		NotityObserver();
		return true;
	}
	return false;
}


int CShell::GetPositionx()
{
	return m_pos.x/32;
}


int CShell::GetPositiony()
{
	return m_pos.y/32;
}

void CShell::DraeEffects(IplImage * pbk,int x,int y,int id)
{
	if (pbk != NULL && m_picture[id] != NULL)
	{
		for (int i = 0; i <m_picture[id]->height; i++)
		{
			for (int j = 0; j < m_picture[id]->width; j++)
			{
				if (!(x * 32 + i >= 15 * 32 || x * 32 + i < 0 || y * 32 + j >= 16 * 32 || y * 32 + j < 0))
				{
					CV_IMAGE_ELEM(pbk, uchar, x * 32 + i, (y * 32 + j) * 3 + 0) =
						CV_IMAGE_ELEM(m_picture[id], uchar, i, j * 3 + 0);
					CV_IMAGE_ELEM(pbk, uchar, x * 32 + i, (y * 32 + j) * 3 + 1) =
						CV_IMAGE_ELEM(m_picture[id], uchar, i, j * 3 + 1);
					CV_IMAGE_ELEM(pbk, uchar, x * 32 + i, (y * 32 + j) * 3 + 2) =
						CV_IMAGE_ELEM(m_picture[id], uchar, i, j * 3 + 2);
				}
			}
		}
	}
}

void CShell::SetObserver(CObserver* observer)
{
	this->observer = observer;
}


void CShell::NotityObserver()
{
	this->observer->Action();
}
