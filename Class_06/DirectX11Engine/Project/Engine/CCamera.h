#pragma once
#include "CComponent.h"


class CCamera :
    public CComponent
{
private:
    PROJ_TYPE   m_ProjType;

    int         m_CamPriority;  // �����Ŵ����� ��ϵɶ� ī�޶��� �켱����(0 : ����ī�޶�, -1 : �̵�� ī�޶�, 0 ���� ũ�� : ���� ī�޶�)

    float       m_FOV;          // �þ߰�(Field Of View)
    float       m_Far;          // �þ� �ִ�Ÿ�

    float       m_Width;        // ���� ����
    float       m_AspectRatio;  // ��Ⱦ ��

    float       m_Scale;        // �������� ����

    Matrix      m_matView;
    Matrix      m_matProj;

    UINT        m_LayerCheck;


    vector<CGameObject*>    m_vecOpaque;
    vector<CGameObject*>    m_vecMasked;
    vector<CGameObject*>    m_vecTransparent;
    vector<CGameObject*>    m_vecParticle;
    vector<CGameObject*>    m_vecPostProcess;


public:
    void SetCameraPriority(int _Priority);    

    void SetProjType(PROJ_TYPE _Type) { m_ProjType = _Type; }
    void SetFar(float _Far) { m_Far = _Far; }
    void SetFOV(float _FOV) { m_FOV = _FOV; }
    void SetWidth(float _Width) { m_Width = _Width; }
    void SetAspectRaito(float _AR) { m_AspectRatio = _AR; }
	void SetScale(float _Scale) { m_Scale = _Scale; }

	int GetCameraPriority() { return m_CamPriority; }
	PROJ_TYPE GetProjType() { return m_ProjType; }
	float GetFar() { return m_Far; }
	float GetFOV() { return m_FOV; }
	float GetWidth() { return m_Width; }
	float GetAspectRaito() { return m_AspectRatio; }
	float GetScale() { return m_Scale; }

    void LayerCheck(int _LayerIdx);
    void LayerCheckAll() { m_LayerCheck = 0xffffffff; }

    void SortObject();

public:
    virtual void finaltick() override;
    void render();

private:    
    void SortClear();
    void render_opaque();
    void render_masked();
    void render_transparent();
    void render_particle();
    void render_postprocess();
    


    CLONE(CCamera);
public:
    CCamera();
    CCamera(const CCamera& _Other);
    ~CCamera();
};
