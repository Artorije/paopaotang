#pragma once
#include "CObserver.h"
class CObserverJudgeHurt :
    public CObserver
{
public:
    CObserverJudgeHurt(CShell * paodan, CPlayer* player1, CPlayer* player2,CMMap* map);
    ~CObserverJudgeHurt();
    void Action();
};

