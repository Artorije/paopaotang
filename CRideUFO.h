#pragma once
#include "CRide.h"
#include "CRideUFO.h"
class CRideUFO :
    public CRide
{
public:
    CRideUFO();
    ~CRideUFO();
    void LoadPlayer(int type);
    void LoadBody(int type);
    void LoadAppend(int type);
    void SetImagePlayer(IplImage** player);
    void SetImageBody(IplImage** body);
    void SetImageAppend(IplImage** append);
};

