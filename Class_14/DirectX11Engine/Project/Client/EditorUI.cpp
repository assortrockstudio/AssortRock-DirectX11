#include "pch.h"
#include "EditorUI.h"

EditorUI::EditorUI()
{
}

EditorUI::~EditorUI()
{
}

void EditorUI::tick()
{
	ImGui::Begin(m_Name.c_str());


	ImGui::End();
}