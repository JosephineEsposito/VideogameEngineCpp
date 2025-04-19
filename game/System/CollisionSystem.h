/*********************************************************
* The collision system
**********************************************************/
#pragma once

#include "ecs/System.h"
#include "ECS/Component.h"
#include "ECS/Coordinator.h"

class CollisionSystem : public System
{
public:
  CollisionSystem();

  void Update() override;

  void Draw() override {};

  void RemoveEntity(Entity _entity) override;

  bool CheckCollision(Entity _aEntity, Entity _bEntity);

};

