#pragma once
#include "EditorUI.h"

class ListUI :
    public EditorUI
{
private:
    vector<string>  m_vecList;
    int             m_SelectedIdx;

public:
    virtual void render_tick() override;

public:
    ListUI();
    ~ListUI();
};

