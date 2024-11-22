#include "pch.h"
#include "TransformUI.h"


TransformUI::TransformUI()
	: ComponentUI("Transform", "##TransformUI", COMPONENT_TYPE::TRANSFORM)
{
	SetSize(ImVec2(0, 200));
}

TransformUI::~TransformUI()
{
}

void TransformUI::render_tick()
{
	ImGui::Text("TransformUI");
}
