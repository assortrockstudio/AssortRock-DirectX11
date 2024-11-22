#pragma once

class EditorUI;

class CImGuiMgr :
    public CSingleton<CImGuiMgr>
{
    SINGLE(CImGuiMgr);
private:
    HWND                    m_hMainWnd;
    map<string, EditorUI*>  m_mapUI;

    bool                    m_bDemo;

public:
    int init(HWND _hWnd);
    void tick();

private:
    void CreateEditorUI();
};

