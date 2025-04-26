#pragma once

#include "utils/Vec2.h"

namespace MovementSystem
{
  void DisplaceToLeft(Vec2& _pos, const Vec2& _vel);

  void DisplaceToRight(Vec2& _pos, const Vec2& _vel);

  void DisplaceUpwards(Vec2& _pos, const Vec2& _vel);

  void DisplaceDownwards(Vec2& _pos, const Vec2& _vel);

  void DisplaceDownwardsLeftDiagonal(Vec2& _pos, const Vec2& _vel);

  void DisplaceDownwardsRightDiagonal(Vec2& _pos, const Vec2& _vel);
};
