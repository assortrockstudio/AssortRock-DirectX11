#pragma once
#include "EditorUI.h"

class CGameObject;

class Inspector :
    public EditorUI
{
private:
    CGameObject*    m_TargetObject;

public:
    virtual void render_tick() override;


public:
    void SetTargetObject(CGameObject* _Target);



public:
    Inspector();
    ~Inspector();
};

