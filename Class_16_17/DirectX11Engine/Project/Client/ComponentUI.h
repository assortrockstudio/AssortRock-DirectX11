#pragma once
#include "EditorUI.h"

#include <Engine/CGameObject.h>

class ComponentUI :
    public EditorUI
{
private:
    CGameObject*            m_TargetObject;
    const COMPONENT_TYPE    m_Type;

public:
    void SetTarget(CGameObject* _Target);


public:
    virtual void render_tick() = 0;

public:
    ComponentUI(const string& _Name, const string& _ID, COMPONENT_TYPE _Type);    
    ~ComponentUI();
};

