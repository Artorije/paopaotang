#pragma once
#include "CTool.h"
class CToolShell :
    public CTool
{
public:
    CToolShell();
    ~CToolShell();
    void LoadImage();
    void InitPos(int x, int y);
};

