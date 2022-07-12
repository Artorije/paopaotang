#pragma once
#include "CToolDecorator.h"
class CToolDecoratorPurplePotion :
    public CToolDecorator
{
public:
    CToolDecoratorPurplePotion(CTool* tool);
    ~CToolDecoratorPurplePotion();
    void LoadImage();
protected:
    void DecorateColor();
public:
    void InitPos(int x, int y);
};

