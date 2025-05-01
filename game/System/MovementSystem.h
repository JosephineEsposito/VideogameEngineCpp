#pragma once

#include "utils/Vec2.h"

namespace MovementSystem
{
  // linear movement

  /**
   * @brief Displaces the vector to the left
   * @param _pos The position vector
   * @param _vel The velocity vector
   */
  void DisplaceToLeft(Vec2& _pos, const Vec2& _vel);

  /**
   * @brief Displaces the vector upwards
   * @param _pos The position vector
   * @param _vel The velocity vector
   */
  void DisplaceUpwards(Vec2& _pos, const Vec2& _vel);

  /**
   * @brief Displaces the vector to the right
   * @param _pos The position vector
   * @param _vel The velocity vector
   */
  void DisplaceToRight(Vec2& _pos, const Vec2& _vel);

  /**
   * @brief Displaces the vector downwards
   * @param _pos The position vector
   * @param _vel The velocity vector
   */
  void DisplaceDownwards(Vec2& _pos, const Vec2& _vel);


  // diagonal movement

  /**
   * @brief Displaces the vector downwards to the left diagonally
   * @param _pos The position vector
   * @param _vel The velocity vector
   */
  void DisplaceDownwardsLeftDiagonal(Vec2& _pos, const Vec2& _vel);

  /**
   * @brief Displaces the vector upwards to the left diagonally
   * @param _pos The position vector
   * @param _vel The velocity vector
   */
  void DisplaceUpwardsLeftDiagonal(Vec2& _pos, const Vec2& _vel);
  
  /**
   * @brief Displaces the vector downwards to the right diagonally
   * @param _pos The position vector
   * @param _vel The velocity vector
   */
  void DisplaceDownwardsRightDiagonal(Vec2& _pos, const Vec2& _vel);

  /**
   * @brief Displaces the vector upwards to the right diagonally
   * @param _pos The position vector
   * @param _vel The velocity vector
   */
  void DisplaceUpwardsRightDiagonal(Vec2& _pos, const Vec2& _vel);
};
