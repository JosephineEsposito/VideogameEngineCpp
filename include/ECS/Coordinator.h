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

  Coordinator();

  Coordinator(const Coordinator&) = delete;

#pragma endregion

  void Init();

  static Coordinator& GetInstance();

  Coordinator& operator=(const Coordinator) = delete;

#pragma region | Entity
  Entity CreateEntity();

  void DestroyEntity(Entity _entity);
#pragma endregion

#pragma region | Components
  template<typename T>
  bool HasComponent(Entity _entity)
  {
    return m_pComponentManager->HasComponent<T>(_entity);
  }

  template<typename T>
  T& GetComponent(Entity _entity)
  {
    return m_pComponentManager->GetComponent<T>(_entity);
  }

  template<typename T>
  void AddComponent(Entity _entity, const T& _component)
  {
    m_pComponentManager->AddComponent<T>(_entity, _component);
  }
#pragma endregion

#pragma region | System
  template<typename T>
  T* RegisterSystem()
  {
    return static_cast<T*>(m_pSystemManager->RegisterSystem<T>());
  }

  template<typename T>
  T* GetSystem() const
  {
    return static_cast<T*>(m_pSystemManager->GetSystem<T>());
  }


#pragma endregion

  ComponentManager* m_pComponentManager;
  EntityManager* m_pEntityManager;
  SystemManager* m_pSystemManager;
};