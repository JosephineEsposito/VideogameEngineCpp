#pragma once

#include "utils/Scene.h"
#include "utils/Color.h"


class MenuScene : public Scene
{
public:
  /**
   * @brief The default constructor
   */
  MenuScene();

  /**
   * @brief Initializes the scene
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
   * @brief Unload the scene
   */
  void Unload() override;

  /**
   * @brief The state of the scene
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
   * @brief The subtext
   */
  const char* m_cText;

};

