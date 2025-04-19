#include <typeinfo>

#include "Engine/Manager/SystemManager.h"


SystemManager::SystemManager(ComponentManager* componentManager)
  : m_pComponentManager(componentManager)
{
}

SystemManager::~SystemManager()
{
  for (auto& pair : m_lSystems)
  {
    delete pair.second;
  }
  m_lSystems.clear();
}

void SystemManager::RemoveEntityFromSystem(Entity entity)
{
  for (auto& pair : m_lSystems)
  {
    if (pair.second)
    {
      pair.second->RemoveEntity(entity);
    }
  }
}
