#include "pch.h"
#include "Inspector.h"

#include <Engine/CLevelMgr.h>
#include <Engine/CLevel.h>
#include <Engine/CGameObject.h>
#include <Engine/components.h>


Inspector::Inspector()
	: EditorUI("Inspector", "##Inspector")
	, m_TargetObject(nullptr)
{
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
			CGameObject* pTarget = pLevel->FindObjectByName(L"Player");
			if (nullptr != pTarget)
			{
				SetTargetObject(pTarget);
			}
		}
		return;
	}


	Vec3 vPos = m_TargetObject->Transform()->GetRelativePos();
	Vec3 vScale = m_TargetObject->Transform()->GetRelativeScale();
	Vec3 vRoation = m_TargetObject->Transform()->GetRelativeRotation();

	ImGui::InputFloat3("Position", vPos);
	ImGui::InputFloat3("Scale", vScale);
	ImGui::InputFloat3("Rotation", vRoation);
}

void Inspector::SetTargetObject(CGameObject* _Target)
{
	m_TargetObject = _Target;


}