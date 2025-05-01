#pragma once

/**
 * @brief Represents the possible states of a scene. Add here values if creating more than the provided states
 */
enum class SceneState : int
{
  INIT,
  MENU,
  PLAYING,
  GAMEOVER,
};