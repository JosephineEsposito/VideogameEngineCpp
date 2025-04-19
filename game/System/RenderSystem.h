/*********************************************************
* The rendering system
**********************************************************/
#pragma once

#include "ECS/System.h"
#include "ECS/Coordinator.h"
#include "ECS/Component.h"

#include "Engine/ENGINE.h"


class RenderSystem : public System
{
public:
  RenderSystem() = default;

  void Update() override {};

  void Draw() override;

  void RemoveEntity(Entity _entity) override;
};

