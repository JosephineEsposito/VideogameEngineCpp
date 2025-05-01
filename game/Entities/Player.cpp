#include "Player.h"

#include "ECS/Coordinator.h"

#include "Engine/Manager/InputManager.h"
#include "System/MovementSystem.h"

Player::Player(const Vec2 _pos, const Vec2 _vel)
{
  entity = Coordinator::GetInstance().CreateEntity();

  Position position = { _pos };
  Velocity velocity = { _vel };

  SpriteComponent sprite;
  sprite.textureName = "assets/characters/chara.png";


  Coordinator::GetInstance().AddComponent<Position>(entity, position);
  Coordinator::GetInstance().AddComponent<Velocity>(entity, velocity);
  Coordinator::GetInstance().AddComponent<SpriteComponent>(entity, sprite);
}

void Player::Update()
{
  if (InputManager::GetInstance().IsKeyPressed(65))
  {
    Position& playerPos = Coordinator::GetInstance().GetComponent<Position>(entity);
    Velocity& playerVel = Coordinator::GetInstance().GetComponent<Velocity>(entity);

    MovementSystem::DisplaceToLeft(playerPos.pos, playerVel.vel);
  }
  if (InputManager::GetInstance().IsKeyPressed(68))
  {
    Position& playerPos = Coordinator::GetInstance().GetComponent<Position>(entity);
    Velocity& playerVel = Coordinator::GetInstance().GetComponent<Velocity>(entity);

    MovementSystem::DisplaceToRight(playerPos.pos, playerVel.vel);
  }
}

void Player::Draw()
{
  Position& pos = Coordinator::GetInstance().GetComponent<Position>(entity);
  SpriteComponent& spriteComp = Coordinator::GetInstance().GetComponent<SpriteComponent>(entity);

  Sprite playerSprite(spriteComp.textureName);
  playerSprite.Draw(ENGINE::GetInstance().GetScreen(), pos.pos.x, pos.pos.y);
}
//EOF