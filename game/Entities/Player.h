#pragma once

#include "BaseCharacter.h"
#include "ECS/Component.h"
#include "utils/Vec2.h"

class Player : public BaseCharacter
{
public:
  /**
   * @brief The default constructor
   */
  Player() = default;

  /**
   * @brief The constructor of the player
   * @param _pos The position vector
   * @param _vel The velocity vector
   */
  Player(const Vec2 _pos, const Vec2 _vel);

  /**
   * @brief Updates the player's logic
   */
  virtual void Update() override;

  /**
   * @brief Renders the player's sprites
   */
  virtual void Draw() override;

};

