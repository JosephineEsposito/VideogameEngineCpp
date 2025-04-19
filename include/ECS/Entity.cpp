#include "Entity.h"
#include <cassert>


EntityManager::EntityManager()
{
  for (Entity entity = 0; entity < MAX_ENTITIES; ++entity)
  {
    m_lAvailableEntities.push(entity);
  }
}

Entity EntityManager::CreateEntity()
{
  assert(!m_lAvailableEntities.empty() && "Stop! Too many entities in game!");

  Entity id_ = m_lAvailableEntities.front();

  m_lAvailableEntities.pop();
  m_lLivingEntities.insert(id_);

  return id_;
}

void EntityManager::DestroyEntity(Entity _entity)
{
  assert(m_lLivingEntities.find(_entity) != m_lLivingEntities.end() && "This entity does not exist!");

  m_lLivingEntities.erase(_entity);
  m_lAvailableEntities.push(_entity);
}

bool EntityManager::IsEntityAlive(Entity _entity) const
{
  return m_lLivingEntities.find(_entity) != m_lLivingEntities.end();
}
