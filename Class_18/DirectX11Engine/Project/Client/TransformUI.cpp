#include "pch.h"
#include "TransformUI.h"


TransformUI::TransformUI()
	: ComponentUI("Transform", "##TransformUI", COMPONENT_TYPE::TRANSFORM)
{
	SetSize(ImVec2(0, 150));
}

TransformUI::~TransformUI()
{
}

void TransformUI::render_tick()
{	
	// 타이틀 출력
	render_title();


}
