#include "ECS/Coordinator.h"
#include "ECS/Entity.h"
#include "ECS/Component.h"
#include "Engine/Manager/SystemManager.h"

#include "System/CollisionSystem.h"
#include "System/EnemySystem.h"
#include "System/PlayerSystem.h"
#include "System/RenderSystem.h"


Coordinator& Coordinator::GetInstance()
{
  static Coordinator instance;
  return instance;
}


Coordinator::Coordinator()
{
  m_pComponentManager = new ComponentManager();
  m_pEntityManager = new EntityManager();
  m_pSystemManager = new SystemManager(m_pComponentManager);
}


void Coordinator::Init()
{
  m_pSystemManager->RegisterSystem<PlayerSystem>();
  m_pSystemManager->RegisterSystem<EnemySystem>();
  m_pSystemManager->RegisterSystem<CollisionSystem>();
  m_pSystemManager->RegisterSystem<RenderSystem>();
}

// ========== ENTITY ==========

Entity Coordinator::CreateEntity()
{
  return m_pEntityManager->CreateEntity();
}

void Coordinator::DestroyEntity(Entity entity)
{
  m_pEntityManager->DestroyEntity(entity);
  m_pSystemManager->RemoveEntityFromSystem(entity);
}
