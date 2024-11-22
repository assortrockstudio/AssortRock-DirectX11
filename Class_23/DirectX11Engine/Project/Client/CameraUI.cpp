#include "pch.h"
#include "CameraUI.h"


#include <Engine/CCamera.h>

CameraUI::CameraUI()
	: ComponentUI("Camera", "##CameraUI", COMPONENT_TYPE::CAMERA)
{
}

CameraUI::~CameraUI()
{
}


void CameraUI::render_tick()
{
	render_title();

    CCamera* pCam = GetTarget()->Camera();

    PROJ_TYPE ProjType = pCam->GetProjType();

	// PROJ_TYPE
    const char* items[2] = {};

    items[0] = "ORTHOGRAPHIC";
    items[1] = "PERSPECTIVE";

    if (ImGui::BeginCombo("##CameraProjType", items[(UINT)ProjType], 0))
    {
        for (int i = 0; i < 2; ++i)
        {
            const bool is_selected = ((UINT)ProjType == i);
            if (ImGui::Selectable(items[i], is_selected))
            {
                pCam->SetProjType((PROJ_TYPE)i);
            }
        }
        ImGui::EndCombo();
    }


	
	// Ä«¸Þ¶ó Priority

	// FOV

	// Far

	// Width
	// AspectRatio

	// Scale(Orthographic)

	// Layer Check
}