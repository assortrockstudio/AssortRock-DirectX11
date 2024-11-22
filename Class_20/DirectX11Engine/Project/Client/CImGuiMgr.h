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
    template<typename T>
    T* FindEditorUI(const string& _strName);


public:
    int init(HWND _hWnd);
    void tick();

private:
    void CreateEditorUI();
};

template<typename T>
inline T* CImGuiMgr::FindEditorUI(const string& _strName)
{
    map<string, EditorUI*>::iterator iter = m_mapUI.find(_strName);

    if (iter == m_mapUI.end())
        return nullptr;

    T* pUI = dynamic_cast<T*>(iter->second);

    return pUI;
}
