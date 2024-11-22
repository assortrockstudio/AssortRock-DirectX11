#include "pch.h"
#include "CPrefab.h"

#include "CGameObject.h"

CPrefab::CPrefab()
	: CAsset(ASSET_TYPE::PREFAB)
	, m_ProtoObj(nullptr)
{
}

CPrefab::~CPrefab()
{
	if (nullptr != m_ProtoObj)
		delete m_ProtoObj;
}
