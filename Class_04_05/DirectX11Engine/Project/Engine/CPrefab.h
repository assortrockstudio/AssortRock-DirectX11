#pragma once
#include "CAsset.h"

class CGameObject;

class CPrefab :
    public CAsset
{
private:
    CGameObject*    m_ProtoObj;


public:
    CPrefab();
    ~CPrefab();
};

