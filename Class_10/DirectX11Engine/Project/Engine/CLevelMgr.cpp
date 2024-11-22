#include "pch.h"
#include "CLevelMgr.h"

#include "CAssetMgr.h"

#include "CLevel.h"
#include "CLayer.h"


CLevelMgr::CLevelMgr()
	: m_CurLevel(nullptr)
{

}

CLevelMgr::~CLevelMgr()
{
	if (nullptr != m_CurLevel)
	{
		delete m_CurLevel;
	}
}


void CLevelMgr::init()
{
	
}

void CLevelMgr::tick()
{
	if (nullptr != m_CurLevel)
	{
		m_CurLevel->tick();
		m_CurLevel->finaltick();
	}
}
