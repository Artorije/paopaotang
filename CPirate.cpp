#include "CPirate.h"

CPirate::CPirate()
{
	m_die = false;
	m_move = false;
	m_state = 6;
	m_life = 3;
	m_speed = 1;
	m_numfire = 1;
	m_power = 1;
	cout << "生成了海盗" << endl;
}

CPirate::~CPirate()
{
}


void CPirate::InitPos(int x, int y)
{
	m_pos.x = 32 * x;
	m_pos.y = 32 * y;
}
