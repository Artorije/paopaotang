#pragma once
#include "CPlayer.h"
#include "Shell.h"
class CMMap;
class CObserver
{
public:
	CObserver(CShell* paodan,CPlayer* player1,CPlayer* player2,CMMap* map);
	~CObserver();
	virtual void Action() = 0;
protected:
	CShell* paodan;
	CPlayer* player1;
	CPlayer* player2;
	CMMap* map;
};

