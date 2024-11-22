#pragma once
#include "ComponentUI.h"

class MeshRenderUI :
    public ComponentUI
{
private:
   

public:
    virtual void render_tick() override;

    UINT SelectMaterial(DWORD_PTR _Selected);

public:
    MeshRenderUI();
    ~MeshRenderUI();
};
