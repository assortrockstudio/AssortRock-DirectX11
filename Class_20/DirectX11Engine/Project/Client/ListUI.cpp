#include "pch.h"
#include "ListUI.h"


ListUI::ListUI()
	: EditorUI("List", "##List")
    , m_SelectedIdx(0)
{
}

ListUI::~ListUI()
{
}

void ListUI::render_tick()
{
    ImVec2 vWinSize = ImGui::GetWindowContentRegionMax();
    vWinSize.y -= 27;
    vWinSize.x -= 8;

    const char* arr[5] = { "AA", "BB", "CC", "DD", "EE" };

    if (ImGui::BeginListBox("##ListBox", vWinSize))
    {
        for (int i = 0; i < 5; ++i)
        {
            bool bSelected = (i == m_SelectedIdx);                

            if (ImGui::Selectable(arr[i], bSelected))
            {
                m_SelectedIdx = i;
            }
        }

        ImGui::EndListBox();
    }
}