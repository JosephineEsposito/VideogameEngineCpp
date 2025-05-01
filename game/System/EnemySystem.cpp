#include "EnemySystem.h"

#include <vector>
#include <cstdlib> // for rand and srand
#include <ctime> // for seed generation

#include "Engine/Manager/TimerManager.h"


EnemySystem::EnemySystem()
{
  m_fSpawnTimer = 5.0f;

  // we create the timer
  m_pTimer = new Timer(m_fSpawnTimer, 0.0f, true);
}

void EnemySystem::SpawnEnemy()
{
  // if the timer has finished
  if (m_pTimer->IsFinished())
  {
    // we generate a new seed for the rand()
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    Vec2 pos = Vec2((std::rand() % 500), 16.f);

    // we create a new enemy with a random type
    Enemy* enemy = new Enemy(pos, static_cast<EnemyType>(std::rand() % 3));

    // we add the enemy to the vector
    m_lEnemies.push_back(enemy);
    // and reset the timer
    m_pTimer->Reset();
  }
}

void EnemySystem::Update()
{
  SpawnEnemy();

  for (Enemy* enemy : m_lEnemies)
  {
    enemy->Update();
  }

  // updating the local timer with the delta time
  if (!m_pTimer->IsFinished())
  {
    m_pTimer->m_fElapsed += TimerManager::GetInstance().GetDeltaTime();
  }
}

void EnemySystem::Draw()
{
  for (Enemy* enemy : m_lEnemies)
  {
    enemy->Draw();
  }
}
