#pragma once

#include "utils/Scene.h"
#include "utils/Sprite.h"
#include "Entities/Player.h"
#include "System/EnemySystem.h"
#include "System/CollisionSystem.h"
#include "UI/HUD.h"


class GameScene : public Scene
{
public:
  /**
   * @brief The default constructor
   */
  GameScene();

  /**
   * @brief Initialized the scene
   */
  void Init() override;

  /**
   * @brief Updates the scene's logic
   */
  void Update() override;

  /**
   * @brief Renders the scene's sprites
   */
  void Draw() override;

  /**
   * @brief Unloads the scene
   */
  void Unload() override;

  /**
   * @brief The state of the scene
   */
  SceneState m_eState;

private:
  /**
   * @brief The HUD of the scene
   */
  HUD m_oHUD;

  /**
   * @brief The player
   */
  Player* m_pPlayer;

  /**
   * @brief The enemy system
   */
  EnemySystem* m_pEnemySpawner;

  /**
   * @brief The collision system
   */
  CollisionSystem m_pCollisionSystem;

  /**
   * @brief The base map of the scene
   */
  Sprite* m_pMap;
};

