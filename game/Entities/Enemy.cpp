#include "Enemy.h"

#include <cstdlib>  // for rand and srand
#include <ctime>    // for seed generation

#include "utils/Utilities.h"
#include "ECS/Coordinator.h"
#include "System/MovementSystem.h"
#include "Engine/Manager/TimerManager.h"


Enemy::Enemy(Vec2 _pos, EnemyType _type)
{
  // generating the seed for the rand()
  std::srand(static_cast<unsigned int>(std::time(nullptr)));
  // creating a new entity for the enemy
  entity = Coordinator::GetInstance().CreateEntity();

  // creating the components for the entity
  Position position = { _pos };
  Velocity velocity;

  SpriteComponent sprite;

  // creating a local timer for the movement
  timer = Timer(2.0f, 0.0f, true);

  // switch case for the different types of enemies
  switch (_type)
  {
  case EnemyType::RAT:
    // setting the base velocity for the enemy
    velocity.vel = Vec2(20.f, 800.f);
    // randomly choosing a texture
    if (std::rand() % 2 == 0)
    {
      sprite.textureName = "assets/enemies/rat_01.png";
    }
    else
    {
      sprite.textureName = "assets/enemies/rat_02.png";
      // if the special texture is choose increment the velocity
      velocity.vel = velocity.vel * 2;
    }
    break;


  case EnemyType::MAGE:
    // setting the base velocity for the enemy
    velocity.vel = Vec2(30.f, 30.f);
    // randomly choosing a texture
    if (std::rand() % 2 == 0)
    {
      sprite.textureName = "assets/enemies/mage_01.png";
    }
    else
    {
      sprite.textureName = "assets/enemies/mage_02.png";
      // if the special texture is choose increment the velocity
      velocity.vel = velocity.vel * 10;
    }
    break;


  case EnemyType::GHOST:
    // setting the base velocity for the enemy
    velocity.vel = Vec2(600.f, 20.f);
    // randomly choosing a texture
    if (std::rand() % 2 == 0)
    {
      sprite.textureName = "assets/enemies/ghost_01.png";
    }
    else
    {
      sprite.textureName = "assets/enemies/ghost_02.png";
      // if the special texture is choose increment the velocity
      velocity.vel = velocity.vel * 5;
    }
    break;


  default:
    break;
  }

  // adding the components to the entity
  Coordinator::GetInstance().AddComponent<Position>(entity, position);
  Coordinator::GetInstance().AddComponent<Velocity>(entity, velocity);
  Coordinator::GetInstance().AddComponent<SpriteComponent>(entity, sprite);

  // setting its type
  type = _type;

  // setting the boundaries flags to false
  verticalFlag = false; // for the floor and ceiling
  horizontalFlag = false; // for the left and right walls
}

void Enemy::Update()
{
  // obtaining the components
  Position& pos = Coordinator::GetInstance().GetComponent<Position>(entity);
  Velocity& vel = Coordinator::GetInstance().GetComponent<Velocity>(entity);

  // calling the movement methods based on the enemy's type
  switch (type)
  {
  case EnemyType::RAT:
    RatMovement(pos.pos, vel.vel);
    break;
  case EnemyType::MAGE:
    MageMovement(pos.pos, vel.vel);
    break;
  case EnemyType::GHOST:
    GhostMovement(pos.pos, vel.vel);
    break;
  default:
    break;
  }

  // updating the local timer with the delta time
  if (!timer.IsFinished())
  {
    timer.m_fElapsed += TimerManager::GetInstance().GetDeltaTime();
  }
}

void Enemy::Draw()
{
  // obtaining the position and sprite component
  Position& pos = Coordinator::GetInstance().GetComponent<Position>(entity);
  SpriteComponent& spriteComp = Coordinator::GetInstance().GetComponent<SpriteComponent>(entity);

  // loading the spite
  Sprite sprite(spriteComp.textureName);
  sprite.Draw(ENGINE::GetInstance().GetScreen(), pos.pos.x, pos.pos.y);
}


void Enemy::RatMovement(Vec2& _pos, const Vec2 _vel)
{
  // moving vertically only when the timer is finished
  if (timer.IsFinished())
  {
    // resetting the timer
    timer.Reset();
    if (verticalFlag) // it has collided with floor
    {
      // we move upwards
      MovementSystem::DisplaceUpwards(_pos, _vel);
      // we check for boundaries
      if (_pos.y == 0)
      {
        verticalFlag = false;
      }
    }
    else // it has not collided with floor yet
    {
      // we move downwards
      MovementSystem::DisplaceDownwards(_pos, _vel);
      // we check for boundaries
      if (_pos.y >= ENGINE::GetInstance().GetHeight() - 32)
      {
        verticalFlag = true;
      }
    }
  }

  // we move the enemy horizontally
  if (horizontalFlag) // it has collided with wall
  {
    // we move to left
    MovementSystem::DisplaceToLeft(_pos, _vel);
    // we check for boundaries
    if (_pos.x == 16)
    {
      horizontalFlag = false;
    }
  }
  else // it has not collided with wall yet
  {
    // we move to right
    MovementSystem::DisplaceToRight(_pos, _vel);
    // we check for boundaries
    if (_pos.x >= ENGINE::GetInstance().GetWidth() - 32)
    {
      horizontalFlag = true;
    }
  }
}

void Enemy::MageMovement(Vec2& _pos, const Vec2 _vel)
{
  // diagonal
  if (verticalFlag) // we hit the floor
  {
    if (horizontalFlag) // we hit the right wall
    {
      // we move to the left
      MovementSystem::DisplaceUpwardsLeftDiagonal(_pos, _vel);
      // we check the boundaries
      if (_pos.x <= 16)
      {
        horizontalFlag = false;
      }
      // we check if we hit the ceiling
      if (_pos.y <= 16)
      {
        verticalFlag = false;
      }
    }
    else
    {
      // we move to the right
      MovementSystem::DisplaceUpwardsRightDiagonal(_pos, _vel);
      // we check the boundaries
      if (_pos.x >= ENGINE::GetInstance().GetWidth() - 32)
      {
        horizontalFlag = true;
      }
      // we check if we hit the ceiling
      if (_pos.y <= 16)
      {
        verticalFlag = false;
      }
    }
  }
  else // we didn't hit the floor yet or we hit the ceiling
  {
    if (horizontalFlag)
    {
      // we move to the left
      MovementSystem::DisplaceDownwardsLeftDiagonal(_pos, _vel);
      // we check the boundaries
      if (_pos.x <= 16)
      {
        horizontalFlag = false;
      }
      // we check if we hit the floor
      if (_pos.y >= ENGINE::GetInstance().GetHeight() - 32)
      {
        verticalFlag = true;
      }
    }
    else
    {
      // we move to the right
      MovementSystem::DisplaceDownwardsRightDiagonal(_pos, _vel);
      // we check the boundaries
      if (_pos.x >= ENGINE::GetInstance().GetWidth() - 32)
      {
        horizontalFlag = true;
      }
      // we check if we hit the floor
      if (_pos.y >= ENGINE::GetInstance().GetHeight() - 32)
      {
        verticalFlag = true;
      }
    }
  }
}

void Enemy::GhostMovement(Vec2& _pos, const Vec2 _vel)
{
  // vertical
  if (timer.IsFinished()) // we move vertically if the timer finished
  {
    timer.Reset(); // we reset the timer
    if (horizontalFlag) // it has collided with wall
    {
      // we move to left
      MovementSystem::DisplaceToLeft(_pos, _vel);
      // we check the boundaries
      if (_pos.x == 16)
      {
        horizontalFlag = false;
      }
    }
    else // it has not collided with wall yet
    {
      // we move to right
      MovementSystem::DisplaceToRight(_pos, _vel);
      // we check the boundaries
      if (_pos.x >= ENGINE::GetInstance().GetWidth() - 32)
      {
        horizontalFlag = true;
      }
    }
  }

  if (verticalFlag) // it has collided with floor
  {
    // we move upwards
    MovementSystem::DisplaceUpwards(_pos, _vel);
    // we check the boundaries
    if (_pos.y == 0)
    {
      verticalFlag = false;
    }
  }
  else // it has not collided with floor yet
  {
    // we move downwards
    MovementSystem::DisplaceDownwards(_pos, _vel);
    // we check the boundaries
    if (_pos.y >= ENGINE::GetInstance().GetHeight() - 32)
    {
      verticalFlag = true;
    }
  }
}

//EOF