#pragma once

#include <unordered_map>
#include <typeinfo>
#include <string>

#include "ECS/Component.h"
#include "ECS/System.h"

class SystemManager
{
public:
  SystemManager(ComponentManager* componentManager);
  ~SystemManager();


  template<typename T>
  T* RegisterSystem()
  {
    const std::string typeName = typeid(T).name();
    if (m_lSystems.find(typeName) == m_lSystems.end())
    {
      m_lSystems[typeName] = new T();
    }
    return static_cast<T*>(m_lSystems[typeName]);
  }

  template<typename T>
  T* GetSystem()
  {
    const std::string typeName = typeid(T).name();
    if (m_lSystems.find(typeName) != m_lSystems.end())
    {
      return static_cast<T*>(m_lSystems[typeName]);
    }
    return nullptr;
  }

  void RemoveEntityFromSystem(Entity entity);

private:
  ComponentManager* m_pComponentManager;

  std::unordered_map<std::string, System*> m_lSystems;
};
