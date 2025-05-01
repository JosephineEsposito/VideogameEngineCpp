#pragma once

#include "enums/SceneState.h"

class Scene
{
public:
  /**
   * @brief The constructor of the scene
   * @param state The state of the scene
   */
  Scene(SceneState state) : m_eState(state) {}

  /**
   * @brief The destructor of the scene
   */
  virtual ~Scene() {};

  /**
   * @brief Initialized the scene
   */
  virtual void Init() = 0;

  /**
   * @brief Updates the scene
   */
  virtual void Update() = 0;

  /**
   * @brief Draws the scene
   */
  virtual void Draw() = 0;

  /**
   * @brief Unloads the scene
   */
  virtual void Unload() = 0;

  /**
   * @brief The state of the scene
   */
  SceneState m_eState = SceneState::INIT;
};

