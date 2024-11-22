#pragma once

#include "ImGui/imgui.h"

class EditorUI
{
private:
	string			m_Name;
	const string	m_ID;

public:
	void SetName(const string& _Name) { m_Name = _Name; }
	const string& GetName() { return m_Name; }

public:
	virtual void tick();
	virtual void render_tick() = 0;

public:	
	EditorUI(const string& _Name, const string& _ID);
	virtual ~EditorUI();
};

