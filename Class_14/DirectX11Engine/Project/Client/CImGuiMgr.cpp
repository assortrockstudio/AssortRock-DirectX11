#include "pch.h"
#include "CImGuiMgr.h"

#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_win32.h"
#include "ImGui/imgui_impl_dx11.h"

#include <Engine/CDevice.h>

#include "EditorUI.h"

CImGuiMgr::CImGuiMgr()
    : m_hMainWnd(nullptr)
{

}

CImGuiMgr::~CImGuiMgr()
{
    ImGui_ImplDX11_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    // Delete EditorUI
    Safe_Del_Map(m_mapUI);
}

int CImGuiMgr::init(HWND _hWnd)
{
    m_hMainWnd = _hWnd;

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // Enable Docking
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;       // Enable Multi-Viewport / Platform Windows
    //io.ConfigViewportsNoAutoMerge = true;
    //io.ConfigViewportsNoTaskBarIcon = true;
    //io.ConfigViewportsNoDefaultParent = true;
    //io.ConfigDockingAlwaysTabBar = true;
    //io.ConfigDockingTransparentPayload = true;
    //io.ConfigFlags |= ImGuiConfigFlags_DpiEnableScaleFonts;     // FIXME-DPI: Experimental. THIS CURRENTLY DOESN'T WORK AS EXPECTED. DON'T USE IN USER APP!
    //io.ConfigFlags |= ImGuiConfigFlags_DpiEnableScaleViewports; // FIXME-DPI: Experimental.

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsLight();

    // When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
    ImGuiStyle& style = ImGui::GetStyle();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        style.WindowRounding = 0.0f;
        style.Colors[ImGuiCol_WindowBg].w = 1.0f;
    }

    // Setup Platform/Renderer backends
    if (!ImGui_ImplWin32_Init(m_hMainWnd))
        return E_FAIL;

    if (!ImGui_ImplDX11_Init(DEVICE, CONTEXT))
        return E_FAIL;

    CreateEditorUI();

	return S_OK;
}

void CImGuiMgr::tick()
{
    // Start the Dear ImGui frame
    ImGui_ImplDX11_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();
        
    for (const auto& pair : m_mapUI)
    {
        pair.second->tick();
    }

    // Rendering
    ImGui::Render();
    ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

    // Update and Render additional Platform Windows
    if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        ImGui::UpdatePlatformWindows();
        ImGui::RenderPlatformWindowsDefault();
    }
}

void CImGuiMgr::CreateEditorUI()
{
    EditorUI* pUI = nullptr;

    pUI = new EditorUI;
    pUI->SetName("Inspector");
    m_mapUI.insert(make_pair(pUI->GetName(), pUI));

    pUI = new EditorUI;
    pUI->SetName("Outliner");
    m_mapUI.insert(make_pair(pUI->GetName(), pUI));

    pUI = new EditorUI;
    pUI->SetName("Content");
    m_mapUI.insert(make_pair(pUI->GetName(), pUI));
}
