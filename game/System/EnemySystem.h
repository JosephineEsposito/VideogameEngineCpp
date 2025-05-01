/*********************************************************
* The enemy system
**********************************************************/
#pragma once

#include <vector>

#include "ECS/System.h"
#include "Entities/Enemy.h"
#include "utils/Timer.h"

class EnemySystem : public System
{
public:
  /**
   * @brief The default constructor
   */
  EnemySystem();

  /**
   * @brief Updates the logic
   */
  void Update() override;

  /**
   * @brief Renders the sprites
   */
  void Draw() override;

  /**
   * @brief Removes the entity
   * @param _entity The entity to remove
   */
  void RemoveEntity(Entity _entity) {};

  /**
   * @brief A vector containing all the enemies
   */
  std::vector<Enemy*> m_lEnemies;
  
private:
  /**
   * @brief Spawns a new enemy after a certain amount of time
   */
  void SpawnEnemy();

  /**
   * @brief The max timer duration for the spawner
   */
  float m_fSpawnTimer;

  /**
   * @brief The local timer for the spawner
   */
  Timer* m_pTimer;
};

