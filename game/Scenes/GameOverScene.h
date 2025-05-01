#pragma once

#include "utils/Scene.h"
#include "utils/Color.h"


class GameOverScene : public Scene
{
public:
  /**
   * @brief The default constructor
   */
  GameOverScene();

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
   * @brief The scene's state
   */
  SceneState m_eState;

private:
  /**
   * @brief The background color
   */
  Color m_oBackground;

  /**
   * @brief The text color
   */
  Color m_oTextColor;

  /**
   * @brief The title text
   */
  const char* m_cTitle;

  /**
   * @brief The subtitle text
   */
  const char* m_cSubtitle;

  /**
   * @brief The score text
   */
  const char* m_cScore;
};

