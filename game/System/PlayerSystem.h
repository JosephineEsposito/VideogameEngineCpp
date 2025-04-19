/*********************************************************
* The player system
**********************************************************/
#pragma once

#include "ecs/System.h"
#include "ECS/Component.h"
#include "ECS/Coordinator.h"
#include "engine/Manager/InputManager.h"


class PlayerSystem : public System
{
public:
  PlayerSystem();

  void HandleInput(bool _leftPressed, bool _rightPressed);

  void Update() override;

  void Draw() override {};

  void RemoveEntity(Entity _entity) override;

private:
  float m_fSpeed;

  int m_iDirection;
};
