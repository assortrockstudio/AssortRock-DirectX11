#include "pch.h"
#include "EditorUI.h"

EditorUI::EditorUI(const string& _Name, const string& _ID)
	: m_Name(_Name)
	, m_ID(_ID)
	, m_ParentUI(nullptr)
	, m_Active(true)
{
}

EditorUI::~EditorUI()
{
	Safe_Del_Vector(m_vecChildUI);
}

void EditorUI::tick()
{
	// 비활성화 상태면 tick 함수를 실행하지 않음
	if (!m_Active)
		return;

	string fullname = m_Name + m_ID;

	if (IsRootUI())
	{
		ImGui::Begin(fullname.c_str());

		render_tick();

		for (size_t i = 0; i < m_vecChildUI.size(); ++i)
		{
			m_vecChildUI[i]->tick();
		}

		ImGui::End();
	}

	else
	{
		ImGui::BeginChild(fullname.c_str(), m_vChildSize);

		render_tick();

		for (size_t i = 0; i < m_vecChildUI.size(); ++i)
		{
			m_vecChildUI[i]->tick();
		}

		ImGui::EndChild();
	}
}