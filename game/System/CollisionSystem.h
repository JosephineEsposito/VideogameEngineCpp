/*********************************************************
* The collision system
**********************************************************/
#pragma once

#include "ecs/System.h"
#include "ECS/Component.h"
#include "ECS/Coordinator.h"

class CollisionSystem : public System
{
public:
  /**
   * @brief The default constructor
   */
  CollisionSystem();

  /**
   * @brief Updates the logic
   */
  void Update() override;

  /**
   * @brief Renders the sprites
   */
  void Draw() override {};

  /**
   * @brief Removes the entity
   * @param _entity The entity to remove
   */
  void RemoveEntity(Entity _entity) override;

  /**
   * @brief Checks for collisions. This methods checks for collisions based on rect
   * @param _aEntity The first entity
   * @param _bEntity The second entity
   * @return A bool static if the two entities collided
   */
  bool CheckCollision(Entity _aEntity, Entity _bEntity);

};

