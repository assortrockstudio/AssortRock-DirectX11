#include "pch.h"
#include "EditorUI.h"

EditorUI::EditorUI(const string& _Name, const string& _ID)
	: m_Name(_Name)
	, m_ID(_ID)
	, m_ParentUI(nullptr)
	, m_Active(true)
	, m_Seperate(false)
{
}

EditorUI::~EditorUI()
{
	Safe_Del_Vector(m_vecChildUI);
}

bool EditorUI::SetActive(bool _Active)
{
	if (m_Active == _Active)
		return false;

	m_Active = _Active;

	if (m_Active)
		Activate();
	else
		Deactivate();

	return true;
}

void EditorUI::SetFocus()
{
	string fullname = m_Name + m_ID;

	ImGui::SetWindowFocus(fullname.c_str());
}

void EditorUI::tick()
{
	// ��Ȱ��ȭ ���¸� tick �Լ��� �������� ����
	if (!m_Active)
		return;

	string fullname = m_Name + m_ID;

	if (IsRootUI())
	{		
		bool bActive = m_Active;
		ImGui::Begin(fullname.c_str(), &bActive);
		SetActive(bActive);

		render_tick();

		for (size_t i = 0; i < m_vecChildUI.size(); ++i)
		{
			m_vecChildUI[i]->tick();
		}

		ImGui::End();
	}

	else
	{
		if (m_Seperate)
			ImGui::Separator();

		ImGui::BeginChild(fullname.c_str(), m_vChildSize);

		render_tick();

		for (size_t i = 0; i < m_vecChildUI.size(); ++i)
		{
			m_vecChildUI[i]->tick();
		}

		ImGui::EndChild();
	}
}