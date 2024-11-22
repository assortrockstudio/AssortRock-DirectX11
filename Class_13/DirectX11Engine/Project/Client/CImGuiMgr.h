#pragma once


class CImGuiMgr :
    public CSingleton<CImGuiMgr>
{
    SINGLE(CImGuiMgr);
private:
    HWND    m_hMainWnd;

public:
    int init(HWND _hWnd);
};

