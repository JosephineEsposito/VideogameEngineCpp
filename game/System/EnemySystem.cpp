#include "EnemySystem.h"

#include <vector>

#include "ecs/System.h"
#include "ECS/Component.h"
#include "ECS/Coordinator.h"


EnemySystem::EnemySystem()
{
  m_fSpawnTimer = 5.0f;
}

void EnemySystem::SpawnEnemy()
{
  return;
}

void EnemySystem::Update()
{
  for (const Entity& entity : m_lEntities)
  {
    Position& position = Coordinator::GetInstance().GetComponent<Position>(entity);
    Velocity& velocity = Coordinator::GetInstance().GetComponent<Velocity>(entity);

    position.pos.x += velocity.vel.x;
    position.pos.y += velocity.vel.y;

    //@review -> qui puoi aggiungere altre logiche
  }
}

void EnemySystem::RemoveEntity(Entity _entity)
{
  m_lEntities.erase(std::remove(m_lEntities.begin(), m_lEntities.end(), _entity), m_lEntities.end());
}
