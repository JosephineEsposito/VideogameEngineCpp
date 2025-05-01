#include <typeinfo>

#include "Engine/Manager/SystemManager.h"


SystemManager::SystemManager(ComponentManager* componentManager)
  : m_pComponentManager(componentManager)
{
}

SystemManager::~SystemManager()
{
  // we delete all the registered systems
  for (auto& pair : m_lSystems)
  {
    delete pair.second;
  }

  // we clean the map
  m_lSystems.clear();
}

void SystemManager::RemoveEntityFromSystem(Entity entity)
{
  // we remove the entity across all registered systems
  for (auto& pair : m_lSystems)
  {
    if (pair.second)
    {
      pair.second->RemoveEntity(entity);
    }
  }
}
