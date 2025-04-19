/*********************************************************
* The enemy system
**********************************************************/
#pragma once

#include <vector>

#include "ecs/System.h"
#include "ECS/Component.h"
#include "ECS/Coordinator.h"

class EnemySystem : public System
{
public:
  EnemySystem();

  void SpawnEnemy();

  void Update() override;

  void Draw() override {};

  void RemoveEntity(Entity _entity) override;
  
private:
  float m_fSpawnTimer;

  std::vector<Entity> m_lEntities;
};

