#include "pch.h"
#include "MeshRenderUI.h"

#include <Engine/CAssetMgr.h>
#include <Engine/CMeshRender.h>

#include "CImGuiMgr.h"
#include "ListUI.h"


void Test()
{
	int a = 0;
}


MeshRenderUI::MeshRenderUI()
	: ComponentUI("MeshRenderUI", "##MeshRenderUI", COMPONENT_TYPE::MESHRENDER)
{
	SetSize(ImVec2(0, 150));
}

MeshRenderUI::~MeshRenderUI()
{
}

void MeshRenderUI::render_tick()
{
	render_title();

	CMeshRender* pMeshRender = GetTarget()->MeshRender();

	Ptr<CMesh> pMesh = pMeshRender->GetMesh();
	Ptr<CMaterial> pMtrl = pMeshRender->GetMaterial();
	
	string strMeshKey;

	if (nullptr != pMesh)
	{
		strMeshKey = string(pMesh->GetKey().begin(), pMesh->GetKey().end());
	}
	
	ImGui::Text("Mesh      ");
	ImGui::SameLine();
	ImGui::InputText("##MeshName", (char*)strMeshKey.c_str(), strMeshKey.capacity(), ImGuiInputTextFlags_ReadOnly);
	ImGui::SameLine();

	if (ImGui::Button("##MeshBtn", ImVec2(18, 18)))
	{
		// ListUI 를 활성화한다
		ListUI* pListUI = CImGuiMgr::GetInst()->FindEditorUI<ListUI>("List");

		if (nullptr != pListUI && !pListUI->IsActive())
		{			
			pListUI->SetActive(true);
			pListUI->SetFocus();
			
			vector<string> vecNames;
			CAssetMgr::GetInst()->GetAssetNames(ASSET_TYPE::MESH, vecNames);
			pListUI->AddItem(vecNames);
			pListUI->SetCallBack(&Test);
		}		
	}


	string strMtrlKey;
	
	if (nullptr != pMtrl)
	{
		strMtrlKey = string(pMtrl->GetKey().begin(), pMtrl->GetKey().end());
	}
	
	ImGui::Text("Material  ");
	ImGui::SameLine();
	ImGui::InputText("##MaterialName", (char*)strMtrlKey.c_str(), strMtrlKey.capacity(), ImGuiInputTextFlags_ReadOnly);
	ImGui::SameLine();

	if (ImGui::Button("##MaterialBtn", ImVec2(18, 18)))
	{
		// ListUI 를 활성화한다
		ListUI* pListUI = CImGuiMgr::GetInst()->FindEditorUI<ListUI>("List");

		if (nullptr != pListUI)
		{
			if (pListUI->SetActive(true))
			{
				pListUI->SetFocus();

				vector<string> vecNames;
				CAssetMgr::GetInst()->GetAssetNames(ASSET_TYPE::MATERIAL, vecNames);
				pListUI->AddItem(vecNames);
			}
		}
	}
}
