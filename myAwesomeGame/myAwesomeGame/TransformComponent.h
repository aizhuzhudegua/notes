#pragma once
#include "ComponentBase.h"
#include "Vector3.h"


class TransformComponent :
    public ComponentBase
{
    Vector3 position;
    void tick();
};

