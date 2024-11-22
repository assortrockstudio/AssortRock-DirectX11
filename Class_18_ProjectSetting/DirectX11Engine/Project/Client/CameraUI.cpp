#include "pch.h"
#include "CameraUI.h"


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


}