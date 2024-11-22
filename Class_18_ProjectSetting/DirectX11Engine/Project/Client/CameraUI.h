#pragma once
#include "ComponentUI.h"
class CameraUI :
    public ComponentUI
{
public:
    virtual void render_tick() override;

public:
    CameraUI();
    ~CameraUI();
};

