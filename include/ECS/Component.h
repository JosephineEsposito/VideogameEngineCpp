/*********************************************************
* Handler of components.
**********************************************************/
#pragma once

#include <unordered_map>
#include <cstdint>

#include "libs/tigr.h"
#include "utils/Vec2.h"
#include "utils/Sprite.h"
#include "ECS/Entity.h"


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
  Sprite sprite;
};

/**
 * @brief Empty component to mark the player
 */
struct TagPlayer {};

/**
 * @brief Empty component to mark enemies
 */
struct TagEnemy {};

#pragma endregion


class ComponentManager
{
public:
  std::unordered_map<Entity, Position> positions;
  std::unordered_map<Entity, Velocity> velocities;
  std::unordered_map<Entity, Sprite> sprites;
  std::unordered_map<Entity, TagPlayer> players;
  std::unordered_map<Entity, TagEnemy> enemies;

#pragma region | Templates

  template<typename T>
  void AddComponent(Entity _entity, T _component)
  {
    GetComponentMap<T>()[_entity] = _component;
  }

  template<typename T>
  T& GetComponent(Entity _entity)
  {
    return GetComponentMap<T>()[_entity];
  }

  template<typename T>
  bool HasComponent(Entity _entity)
  {
    return GetComponentMap<T>().find(_entity) != GetComponentMap<T>().end();
  }

  template<typename T>
  void RemoveComponent(Entity _entity)
  {
    GetComponentMap<T>().erase(_entity);
  }

#pragma endregion


private:
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
    else if constexpr (std::is_same<T, Sprite>::value)
    {
      return sprites;
    }
    else if constexpr (std::is_same<T, TagPlayer>::value)
    {
      players;
    }
    else if constexpr (std::is_same<T, TagEnemy>::value)
    {
      enemies;
    }
  }
};