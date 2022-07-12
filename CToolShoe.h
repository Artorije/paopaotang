#pragma once
#include "CTool.h"
class CToolShoe :
    public CTool
{
public:
    CToolShoe();
    ~CToolShoe();
    void LoadImage();
    void InitPos(int x, int y);
};

