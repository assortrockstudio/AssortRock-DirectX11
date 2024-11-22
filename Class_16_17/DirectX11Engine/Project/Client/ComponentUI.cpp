#include "pch.h"
#include "ComponentUI.h"

ComponentUI::ComponentUI(const string& _Name, const string& _ID, COMPONENT_TYPE _Type)
	: EditorUI(_Name, _ID)
	, m_TargetObject(nullptr)
	, m_Type(_Type)	
{
}

ComponentUI::~ComponentUI()
{
}

void ComponentUI::SetTarget(CGameObject* _Target)
{
	m_TargetObject = _Target;

	if (nullptr == m_TargetObject)
	{
		SetActive(false);
	}
	else
	{
		if (nullptr == m_TargetObject->GetComponent(m_Type))
		{
			SetActive(false);
		}
		else
		{
			SetActive(true);
		}
	}
}
