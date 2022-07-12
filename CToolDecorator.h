#pragma once
#include "CTool.h"
#include<opencv2\opencv.hpp>
class CToolDecorator :
    public CTool
{
public:
    CTool* m_tool;
    CToolDecorator(CTool* tool);
    ~CToolDecorator();
    virtual void LoadImage();
};

