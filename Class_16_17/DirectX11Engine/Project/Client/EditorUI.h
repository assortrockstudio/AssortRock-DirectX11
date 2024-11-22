#pragma once

#include "ImGui/imgui.h"

class EditorUI
{
private:
	string				m_Name;
	const string		m_ID;

	EditorUI*			m_ParentUI;		// Editor UI 의 부모UI 를 가리킴
	vector<EditorUI*>	m_vecChildUI;	// Editor UI 가 소유하고 있는 자식 UI 들

	ImVec2				m_vChildSize;

	bool				m_Active;

public:
	void SetName(const string& _Name) { m_Name = _Name; }
	const string& GetName() { return m_Name; }

	void SetSize(ImVec2 _Size) { m_vChildSize = _Size; }

	void SetActive(bool _Active) { m_Active = _Active; }

	EditorUI* GetParentUI() { return m_ParentUI; }
	const vector<EditorUI*>& GetChildUI() { return m_vecChildUI; }

	void AddChildUI(EditorUI* _Child) 
	{ 
		_Child->m_ParentUI = this;
		m_vecChildUI.push_back(_Child); 
	}
	
	bool IsRootUI() { return !m_ParentUI; }

public:
	virtual void tick();
	virtual void render_tick() = 0;


public:	
	EditorUI(const string& _Name, const string& _ID);
	virtual ~EditorUI();
};

