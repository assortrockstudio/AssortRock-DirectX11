#pragma once
#include "ComponentUI.h"

class MeshRenderUI :
    public ComponentUI
{
private:
   

public:
    virtual void render_tick() override;

public:
    MeshRenderUI();
    ~MeshRenderUI();
};

