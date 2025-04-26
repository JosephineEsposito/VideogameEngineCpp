#include "MovementSystem.h"

#include "Engine/ENGINE.h"

#include "Engine/Manager/TimerManager.h"

void MovementSystem::DisplaceToLeft(Vec2& _pos, const Vec2& _vel)
{
  _pos.x -= _vel.x * TimerManager::GetInstance().GetDeltaTime();
  
  if (_pos.x < 16)
  {
    _pos.x = 16;
  }
}

void MovementSystem::DisplaceToRight(Vec2& _pos, const Vec2& _vel)
{
  _pos.x += _vel.x * TimerManager::GetInstance().GetDeltaTime();

  if (_pos.x > ENGINE::GetInstance().GetWidth() - 32)
  {
    _pos.x = ENGINE::GetInstance().GetWidth() - 32;
  }
}


void MovementSystem::DisplaceUpwards(Vec2& _pos, const Vec2& _vel)
{
  _pos.y -= _vel.y * TimerManager::GetInstance().GetDeltaTime();

  if (_pos.y < 0)
  {
    _pos.y = 0;
  }
}

void MovementSystem::DisplaceDownwards(Vec2& _pos, const Vec2& _vel)
{
  _pos.y += _vel.y * TimerManager::GetInstance().GetDeltaTime();

  if (_pos.y > ENGINE::GetInstance().GetHeight() - 32)
  {
    _pos.y = ENGINE::GetInstance().GetHeight() - 32;
  }
}

void MovementSystem::DisplaceDownwardsLeftDiagonal(Vec2& _pos, const Vec2& _vel)
{
  _pos.x -= _vel.x * TimerManager::GetInstance().GetDeltaTime();
  _pos.y += _vel.y * TimerManager::GetInstance().GetDeltaTime();

  if (_pos.x < 16)
  {
    _pos.x = 16;
  }

  if (_pos.y > ENGINE::GetInstance().GetHeight() - 32)
  {
    _pos.y = ENGINE::GetInstance().GetHeight() - 32;
  }
}

void MovementSystem::DisplaceDownwardsRightDiagonal(Vec2& _pos, const Vec2& _vel)
{
  _pos.x += _vel.x * TimerManager::GetInstance().GetDeltaTime();
  _pos.y += _vel.y * TimerManager::GetInstance().GetDeltaTime();

  if (_pos.x > ENGINE::GetInstance().GetWidth() - 32)
  {
    _pos.x = ENGINE::GetInstance().GetWidth() - 32;
  }

  if (_pos.y > ENGINE::GetInstance().GetHeight() - 32)
  {
    _pos.y = ENGINE::GetInstance().GetHeight() - 32;
  }
}

//EOF