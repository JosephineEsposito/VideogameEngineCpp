/*********************************************************
* Registers and handles entities, components and systems
**********************************************************/
#pragma once

#include <memory>

#include "ECS/Entity.h"
#include "ECS/Component.h"
#include "Engine/Manager/SystemManager.h"


class Coordinator
{
public:
#pragma region | Constructor and Destructor Methods
  /**
   * @brief The default constructor
   */
  Coordinator();

  /**
   * @brief The copy constructor. Deleted for this is a singleton
   * @param  The coordinator to copy
   */
  Coordinator(const Coordinator&) = delete;

#pragma endregion
  /**
   * @brief Initialize the coordinator
   */
  void Init();

  /**
   * @brief Returns a reference to the static instance of the coordinator
   * @return A reference to the static instance of the coordinator
   */
  static Coordinator& GetInstance();

  /**
   * @brief The assign and copy operator. Deleted for this is a singleton
   * @param  The coordinator to copy
   * @return A reference to the copied coordinator
   */
  Coordinator& operator=(const Coordinator) = delete;

#pragma region | Entity
  /**
   * @brief Creates a new entity
   * @return The newly created entity
   */
  Entity CreateEntity();

  /**
   * @brief Destroys an entity
   * @param _entity The entity to destroy
   */
  void DestroyEntity(Entity _entity);
#pragma endregion

#pragma region | Components
  /**
   * @brief Checks if the entity has a component
   * @tparam T The component
   * @param _entity The entity
   * @return A bool stating if the entity has the component
   */
  template<typename T>
  bool HasComponent(Entity _entity)
  {
    return m_pComponentManager->HasComponent<T>(_entity);
  }

  /**
   * @brief Returns the specified component of an entity
   * @tparam T The component
   * @param _entity The entity
   * @return The specified component
   */
  template<typename T>
  T& GetComponent(Entity _entity)
  {
    return m_pComponentManager->GetComponent<T>(_entity);
  }

  /**
   * @brief Registers a new component to an entity
   * @tparam T The component's class to add
   * @param _entity The entity to which the component is added
   * @param _component The component to add
   */
  template<typename T>
  void AddComponent(Entity _entity, const T& _component)
  {
    m_pComponentManager->AddComponent<T>(_entity, _component);
  }
#pragma endregion

#pragma region | System
  /**
   * @brief Registers a new system
   * @tparam T The system to register
   * @return The registered system
   */
  template<typename T>
  T* RegisterSystem()
  {
    return static_cast<T*>(m_pSystemManager->RegisterSystem<T>());
  }

  /**
   * @brief Returns the specified system
   * @tparam T The specified system
   * @return A pointer to the system
   */
  template<typename T>
  T* GetSystem() const
  {
    return static_cast<T*>(m_pSystemManager->GetSystem<T>());
  }


#pragma endregion
  /**
   * @brief The component manager
   */
  ComponentManager* m_pComponentManager;

  /**
   * @brief The entity manager
   */
  EntityManager* m_pEntityManager;

  /**
   * @brief The system manager
   */
  SystemManager* m_pSystemManager;
};