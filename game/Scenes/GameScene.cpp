#include "GameScene.h"

#include "Engine/ENGINE.h"
#include "Engine/Manager/TimerManager.h"
#include "Engine/Manager/SceneManager.h"
#include "Engine/Manager/InputManager.h"
#include "Engine/Manager/GameManager.h"
#include "System/MovementSystem.h"
#include "Entities/Enemy.h"
#include "utils/Vec2.h"
#include "utils/Utilities.h"

GameScene::GameScene() : Scene(SceneState::PLAYING)
{
  ENGINE::Log("GameScene", "Constructor", "Constructor called.");
  // we set the scene state
  m_eState = SceneState::PLAYING;

  m_oHUD = HUD();

  m_pMap = nullptr;
  m_pPlayer = nullptr;

  m_pEnemySpawner = nullptr;
}

void GameScene::Init()
{
  ENGINE::Log("GameScene", "Init", "Starting Init");

  m_oHUD.Init();

  m_pMap = new Sprite("assets/tiles/map.png");

  m_pPlayer = new Player(Vec2(384.0f, 768.0f), Vec2(64.0f, 0.0f));

  m_pEnemySpawner = new EnemySystem();

  GameManager::GetInstance().LoadScore();
  TimerManager::GetInstance().m_pLevelTimer->Reset();
}


void GameScene::Update()
{
  m_oHUD.Update();
  m_pPlayer->Update();
  m_pEnemySpawner->Update();
  
  // we check for collision
  if (!m_pPlayer)
  {
    return;
  }
  for (Enemy* enemy : m_pEnemySpawner->m_lEnemies)
  {
    if (m_pCollisionSystem.CheckCollision(m_pPlayer->entity, enemy->entity))
    {
      // we save the timer
      float score = static_cast<float>(TimerManager::GetInstance().m_pLevelTimer->m_fElapsed);

      // we verify and save the score
      GameManager& gameManager = GameManager::GetInstance();
      if (gameManager.IsNewHighScore(score))
      {
        ENGINE::GetInstance().Log("GameScene", "Update", "New highscore saved!");
      }

      // we change scene
      SceneManager::GetInstance().ChangeScene(SceneState::GAMEOVER);
    }
  }
}

void GameScene::Draw()
{
  m_pMap->Draw(ENGINE::GetInstance().GetScreen());

  m_oHUD.Draw();
  m_pPlayer->Draw();
  m_pEnemySpawner->Draw();
}

void GameScene::Unload()
{
  m_oHUD.Unload();
  delete m_pPlayer;
  m_pPlayer = nullptr;
  delete m_pEnemySpawner;
  m_pEnemySpawner = nullptr;
}

