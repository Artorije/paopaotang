#pragma once
#include "CTool.h"
class CToolPower :
    public CTool
{
public:
    CToolPower();
    ~CToolPower();
    void LoadImage();
    void InitPos(int x, int y);
};

