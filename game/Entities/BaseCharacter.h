#pragma once

#include "ECS/Entity.h"

class BaseCharacter
{
public:
  /**
   * @brief The default constructor
   */
  BaseCharacter() = default;

  /**
   * @brief Updates the logic
   */
  virtual void Update() = 0;

  /**
   * @brief Renders the sprites
   */
  virtual void Draw() = 0;

  /**
   * @brief The entity
   */
  Entity entity;
};

