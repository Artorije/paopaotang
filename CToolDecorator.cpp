#include "CToolDecorator.h"

CToolDecorator::CToolDecorator(CTool* tool)
{
	m_tool = tool;
}

CToolDecorator::~CToolDecorator()
{
}

void CToolDecorator::LoadImage()
{
	m_tool->LoadImage();
}
