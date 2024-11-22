#pragma once

#include "ImGui/imgui.h"

class EditorUI
{
private:
	string		m_Name;

public:
	void SetName(const string& _Name) { m_Name = _Name; }
	const string& GetName() { return m_Name; }

public:
	virtual void tick();

public:
	EditorUI();
	virtual ~EditorUI();
};

