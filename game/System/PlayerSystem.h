/*********************************************************
* The player system
**********************************************************/
#pragma once

#include "ecs/System.h"
#include "ECS/Component.h"
#include "ECS/Coordinator.h"
#include "engine/Manager/InputManager.h"


class PlayerSystem : public System
{
public:
  /**
   * @brief The default constructor
   */
  PlayerSystem();

  /**
   * @brief Handles the input for the player
   * @param _leftPressed If the left key has been pressed
   * @param _rightPressed If the right key has been pressed
   */
  void HandleInput(bool _leftPressed, bool _rightPressed);

  /**
   * @brief Updates the logic
   */
  void Update() override;

  /**
   * @brief Renders the sprites
   */
  void Draw() override {};

  /**
   * @brief Removes the entities
   * @param _entity The entity to remove
   */
  void RemoveEntity(Entity _entity) override;

private:
  /**
   * @brief The speed of the player
   */
  float m_fSpeed;

  /**
   * @brief The direction of the player
   */
  int m_iDirection;
};
