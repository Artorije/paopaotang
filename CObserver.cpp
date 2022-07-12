#include "CObserver.h"

CObserver::CObserver(CShell* paodan, CPlayer* player1, CPlayer* player2,CMMap* map)
{
	this->paodan = paodan;
	this->player1 = player1;
	this->player2 = player2;
	this->map = map;
}

CObserver::~CObserver()
{
}
