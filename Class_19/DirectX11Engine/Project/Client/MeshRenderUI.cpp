#include "pch.h"
#include "MeshRenderUI.h"

#include <Engine/CAssetMgr.h>
#include <Engine/CMeshRender.h>


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
	
	string strMeshKey = string(pMesh->GetKey().begin(), pMesh->GetKey().end());
	ImGui::Text("Mesh      ");
	ImGui::SameLine();
	ImGui::InputText("##MeshName", (char*)strMeshKey.c_str(), strMeshKey.capacity(), ImGuiInputTextFlags_ReadOnly);


	string strMtrlKey = string(pMtrl->GetKey().begin(), pMtrl->GetKey().end());
	ImGui::Text("Material  ");
	ImGui::SameLine();
	ImGui::InputText("##MaterialName", (char*)strMtrlKey.c_str(), strMtrlKey.capacity(), ImGuiInputTextFlags_ReadOnly);
}
