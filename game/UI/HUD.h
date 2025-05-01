#pragma once

#include "utils/Color.h"
#include "utils/Vec2.h"
#include "utils/Sprite.h"

class HUD
{
public:
  /**
   * @brief The default constructor
   */
  HUD();

  /**
   * @brief Initialized the HUD
   */
  void Init();

  /**
   * @brief Updates the logic
   */
  void Update();

  /**
   * @brief Renders the sprites
   */
  void Draw();

  /**
   * @brief Unloads the interface
   */
  void Unload();

private:
  /**
   * @brief The timer value of the game. This is a reference of the engine's timer
   */
  int m_iTimer;

  /**
   * @brief The color of the text
   */
  Color textColor;

  /**
   * @brief The icon of the timer
   */
  Sprite* timerIcon;
};

