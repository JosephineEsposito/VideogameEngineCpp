/*********************************************************
* Handler of components.
**********************************************************/
#pragma once

#include <unordered_map>
#include <cstdint>
#include <string>

#include "utils/Vec2.h"
#include "utils/Sprite.h"
#include "ECS/Entity.h"

#include "Engine/ENGINE.h"

#pragma region | Components
/**
 * @brief The position component
 */
struct Position
{ 
  Vec2 pos;
};

/**
 * @brief The velocity component
 */
struct Velocity
{ 
  Vec2 vel;
};

/**
 * @brief The sprite component
 */
struct SpriteComponent
{
  std::string textureName;
};


#pragma endregion


class ComponentManager
{
public:
  /**
   * @brief The map of entity with position component
   */
  std::unordered_map<Entity, Position> positions;

  /**
   * @brief The map of entity with velocity component
   */
  std::unordered_map<Entity, Velocity> velocities;

  /**
   * @brief The map of entity with sprite component
   */
  std::unordered_map<Entity, SpriteComponent> sprites;

#pragma region | Templates
  /**
   * @brief Adds a new component to an entity
   * @tparam T The component class to add
   * @param _entity The entity
   * @param _component The component to add
   */
  template<typename T>
  void AddComponent(Entity _entity, T _component)
  {
    GetComponentMap<T>()[_entity] = _component;
  }

  /**
   * @brief Returns the component from an entity
   * @tparam T The component class
   * @param _entity The entity
   * @return The component of the entity
   */
  template<typename T>
  T& GetComponent(Entity _entity)
  {
    return GetComponentMap<T>()[_entity];
  }

  /**
   * @brief Checks if an entity has a component
   * @tparam T The component class
   * @param _entity The entity
   * @return A bool stating if the entity has the component
   */
  template<typename T>
  bool HasComponent(Entity _entity)
  {
    return GetComponentMap<T>().find(_entity) != GetComponentMap<T>().end();
  }

  /**
   * @brief Removes a component from an entity
   * @tparam T The component class
   * @param _entity The entity
   */
  template<typename T>
  void RemoveComponent(Entity _entity)
  {
    GetComponentMap<T>().erase(_entity);
  }

#pragma endregion


private:
  /**
   * @brief Returns the component map
   * @tparam T The component class
   * @return The map of the entitiy and component
   */
  template<typename T>
  std::unordered_map<Entity, T>& GetComponentMap()
  {
    if constexpr (std::is_same<T, Position>::value)
    {
      return positions;
    }
    else if constexpr (std::is_same<T, Velocity>::value)
    {
      return velocities;
    }
    else if constexpr (std::is_same<T, SpriteComponent>::value)
    {
      return sprites;
    }
    else
    {
      ENGINE::Log("ComponentManager", "GetComponentMap", "ERROR: Component type not found!");
    }
  }
};