#include "Entity.h"
#include <cassert>


EntityManager::EntityManager()
{
  // fills the queue with the entitites
  for (Entity entity = 0; entity < MAX_ENTITIES; ++entity)
  {
    m_lAvailableEntities.push(entity);
  }
}

Entity EntityManager::CreateEntity()
{
  // checks if there are too many entities in the game
  assert(!m_lAvailableEntities.empty() && "Stop! Too many entities in game!");

  // gets the front entity
  Entity id_ = m_lAvailableEntities.front();

  // moves it from the available to the living queue
  m_lAvailableEntities.pop();
  m_lLivingEntities.insert(id_);

  // returns the entity's id
  return id_;
}

void EntityManager::DestroyEntity(Entity _entity)
{
  // checks if the entity exists
  assert(m_lLivingEntities.find(_entity) != m_lLivingEntities.end() && "This entity does not exist!");

  // moves the entity back to the available queue
  m_lLivingEntities.erase(_entity);
  m_lAvailableEntities.push(_entity);
}

bool EntityManager::IsEntityAlive(Entity _entity) const
{
  // checks if the entity is alive
  return m_lLivingEntities.find(_entity) != m_lLivingEntities.end();
}
