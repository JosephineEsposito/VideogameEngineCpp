#include "GameScene.h"

#include "Engine/ENGINE.h"

#include "Engine/Manager/TimerManager.h"
#include "Engine/Manager/SceneManager.h"
#include "Engine/Manager/InputManager.h"

#include "System/MovementSystem.h"

#include "utils/Vec2.h"


GameScene::GameScene() : Scene(SceneState::PLAYING)
{
  ENGINE::Log("GameScene", "Constructor", "Constructor called.");
  // we set the scene state
  m_eState = SceneState::PLAYING;
  m_hud = HUD();

  map = nullptr;
  player = 0;
}

void GameScene::Init()
{
  ENGINE::Log("GameScene", "Init", "Starting Init");

  m_hud.Init();

  map = new Sprite("assets/tiles/map.png");


  player = Coordinator::GetInstance().CreateEntity();

  Position playerPos = { Vec2(384.0f, 768.0f) };
  Coordinator::GetInstance().AddComponent<Position>(player, playerPos);

  Velocity playerVel = { Vec2(64.0f, 0.0f) };
  Coordinator::GetInstance().AddComponent<Velocity>(player, playerVel);

  SpriteComponent playerSprite;
  playerSprite.textureName = "assets/characters/chara.png";
  Coordinator::GetInstance().AddComponent<SpriteComponent>(player, playerSprite);

  TimerManager::GetInstance().CreateTimer("LevelTimer", 120.0f);
}


void GameScene::Update()
{
  // esegui logica, chiama gli update di ecs, etc.
  m_hud.Update();

  
  if (TimerManager::GetInstance().IsTimerFinished("LevelTimer"))
  {
    ENGINE::Log("GameScene", "Update", "Time's up! Calculate Score and show game over.");
    
    SceneManager::GetInstance().ChangeScene(SceneState::GAMEOVER);
  }


  if (InputManager::GetInstance().IsKeyPressed(65))
  {
    Position& playerPos = Coordinator::GetInstance().GetComponent<Position>(player);
    Velocity& playerVel = Coordinator::GetInstance().GetComponent<Velocity>(player);

    MovementSystem::DisplaceToLeft(playerPos.pos, playerVel.vel);
  }
  if (InputManager::GetInstance().IsKeyPressed(68))
  {
    Position& playerPos = Coordinator::GetInstance().GetComponent<Position>(player);
    Velocity& playerVel = Coordinator::GetInstance().GetComponent<Velocity>(player);

    MovementSystem::DisplaceToRight(playerPos.pos, playerVel.vel);
  }
}

void GameScene::Draw()
{
  map->Draw(ENGINE::GetInstance().getScreen());
  // esegui render, chiama i render di ecs, etc.
  m_hud.Draw();

  Position& pos = Coordinator::GetInstance().GetComponent<Position>(player);
  SpriteComponent& spriteComp = Coordinator::GetInstance().GetComponent<SpriteComponent>(player);

  Sprite playerSprite(spriteComp.textureName);
  playerSprite.Draw(ENGINE::GetInstance().getScreen(), pos.pos.x, pos.pos.y);
}

void GameScene::Unload()
{
  // pulisci le risorse se serve
  m_hud.Unload();
}

