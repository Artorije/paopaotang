#include "CBrick.h"

CBrick::CBrick()
{
}

CBrick::~CBrick()
{
}


void CBrick::AddBrick(CBrick* b)
{
    subordinates.push_back(b);
}


void CBrick::FixBrick(IplImage* pimg)
{
    brick_image = pimg;
}
