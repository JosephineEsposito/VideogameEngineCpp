#pragma once

#include <unordered_map>
#include <typeinfo>
#include <string>

#include "ECS/Component.h"
#include "ECS/System.h"

class SystemManager
{
public:
  /**
   * @brief The default constructor of the manager
   * @param componentManager The component manager
   */
  SystemManager(ComponentManager* componentManager);

  /**
   * @brief The default constructor of the manager
   */
  ~SystemManager();

  /**
   * @brief Registers a new system
   * @tparam T The system to register
   * @return The Registered system
   */
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

  /**
   * @brief Returns the specified system
   * @tparam T The specified system
   * @return A pointer to the specified system
   */
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

  /**
   * @brief Removes an entity across all the systems
   * @param entity The entity to remove
   */
  void RemoveEntityFromSystem(Entity entity);

private:
  /**
   * @brief A pointer to the component manager
   */
  ComponentManager* m_pComponentManager;

  /**
   * @brief An unordered map containing all the registered systems
   */
  std::unordered_map<std::string, System*> m_lSystems;
};
