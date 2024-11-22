#include "pch.h"
#include "Inspector.h"

#include <Engine/CLevelMgr.h>
#include <Engine/CLevel.h>
#include <Engine/CGameObject.h>
#include <Engine/components.h>

#include "TransformUI.h"
#include "MeshRenderUI.h"

Inspector::Inspector()
	: EditorUI("Inspector", "##Inspector")
	, m_TargetObject(nullptr)
	, m_arrComUI{}
{
	// TransformUI ����
	m_arrComUI[(UINT)COMPONENT_TYPE::TRANSFORM] = new TransformUI;
	m_arrComUI[(UINT)COMPONENT_TYPE::TRANSFORM]->SetActive(false);
	AddChildUI(m_arrComUI[(UINT)COMPONENT_TYPE::TRANSFORM]);

	// MeshRenderUI ����
	m_arrComUI[(UINT)COMPONENT_TYPE::MESHRENDER] = new MeshRenderUI;	
	AddChildUI(m_arrComUI[(UINT)COMPONENT_TYPE::MESHRENDER]);
}

Inspector::~Inspector()
{
	
}

void Inspector::render_tick()
{
	if (nullptr == m_TargetObject)
	{
		CLevel* pLevel = CLevelMgr::GetInst()->GetCurrentLevel();
		if (nullptr != pLevel)
		{
			CGameObject* pTarget = pLevel->FindObjectByName(L"TileMap");
			if (nullptr != pTarget)
			{
				SetTargetObject(pTarget);
			}
		}
		return;
	}

	ImGui::Text("Inspector");
}

void Inspector::SetTargetObject(CGameObject* _Target)
{
	m_TargetObject = _Target;

	for (UINT i = 0; i < (UINT)COMPONENT_TYPE::END; ++i)
	{	
		// �ش� ������Ʈ�� ����� UI �� �����Ǿ����� �ʱ� ������ nullptr üũ ���־�� ��
		if (nullptr == m_arrComUI[i])
			continue;

		m_arrComUI[i]->SetTarget(m_TargetObject);
	}	
}