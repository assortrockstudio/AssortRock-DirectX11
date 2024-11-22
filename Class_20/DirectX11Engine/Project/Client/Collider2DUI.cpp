#include "pch.h"
#include "Collider2DUI.h"


Collider2DUI::Collider2DUI()
	: ComponentUI("Collider2D", "##Collider2DUI", COMPONENT_TYPE::COLLIDER2D)
{
	SetSize(ImVec2(0, 300));
}

Collider2DUI::~Collider2DUI()
{
}


void Collider2DUI::render_tick()
{
	render_title();


}