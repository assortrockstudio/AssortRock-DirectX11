#include "pch.h"
#include "EditorUI.h"

EditorUI::EditorUI(const string& _Name, const string& _ID)
	: m_Name(_Name)
	, m_ID(_ID)
{
}

EditorUI::~EditorUI()
{
}

void EditorUI::tick()
{
	string fullname = m_Name + m_ID;

	ImGui::Begin(fullname.c_str());

	render_tick();

	ImGui::End();
}