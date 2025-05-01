#pragma once

#include "BaseCharacter.h"

#include "ECS/Component.h"

#include "enums/EnemyType.h"

#include "utils/Vec2.h"
#include "utils/Timer.h"

class Enemy : public BaseCharacter
{
public:
  /**
   * @brief The default constructor
   */
  Enemy() = default;

  /**
   * @brief The cosntructor of the enemy
   * @param _pos The position vector
   * @param _type The enemy type
   */
  Enemy(const Vec2 _pos, const EnemyType _type);

  /**
   * @brief Updates the enemy's logic
   */
  virtual void Update() override;

  /**
   * @brief Renders the enemy's sprites
   */
  virtual void Draw() override;

protected:
  /**
   * @brief The movement of the rat enemy
   * @param _pos The position vector
   * @param _vel The velocity vector
   */
  void RatMovement(Vec2& _pos, const Vec2 _vel);

  /**
   * @brief The movement of the mage enemy
   * @param _pos The position vector
   * @param _vel The velocity vector
   */
  void MageMovement(Vec2& _pos, const Vec2 _vel);

  /**
   * @brief The movement of the ghost enemy
   * @param _pos The position vector
   * @param _vel The velocity vector
   */
  void GhostMovement(Vec2& _pos, const Vec2 _vel);

private:
  /**
   * @brief The enemy type
   */
  EnemyType type;

  /**
   * @brief The horizontal flag for walls collision
   */
  bool horizontalFlag;

  /**
   * @brief The vertical flag for ceiling and floor collision
   */
  bool verticalFlag;

  /**
   * @brief The local timer for movement
   */
  Timer timer;
};

