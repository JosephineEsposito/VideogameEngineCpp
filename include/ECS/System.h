/*********************************************************
* Handler of systems
**********************************************************/
#pragma once

#include <set>

#include "ECS/Entity.h"


class System
{
public:
  /**
   * @brief The default destructor
   */
  virtual ~System() = default;

  /**
   * @brief Updates the logic of the system
   */
  virtual void Update() = 0;

  /**
   * @brief Renders the sprites of the system
   */
  virtual void Draw() = 0;

  /**
   * @brief Removes an entity from the system
   * @param _entity The entity to remove
   */
  virtual void RemoveEntity(Entity _entity) = 0;

  /**
   * @brief The set of entities inside the system
   */
  std::set<Entity> m_lEntities;
};

