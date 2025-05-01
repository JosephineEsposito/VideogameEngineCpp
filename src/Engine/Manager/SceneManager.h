/*********************************************************
* Handler of scenes
**********************************************************/
#pragma once

#include <memory>
#include <stack>
#include <unordered_map>

#include "utils/Scene.h"
#include "enums/SceneState.h"

class SceneManager
{
public:
  /**
   * @brief The default constructor
   */
  SceneManager();

  /**
   * @brief The copy constructor. Deleted for this is a singleton
   * @param The manager to copy
   */
  SceneManager(const SceneManager&) = delete;

  /**
   * @brief The assign and copy operator. Deleted for this is a singleton
   * @param The manager to copy
   * @return The copied manager
   */
  SceneManager& operator=(const SceneManager) = delete;

  /**
   * @brief Returns a static instance of the manager
   * @return A reference to the static instance of the manager
   */
  static SceneManager& GetInstance();

  /**
   * @brief Registers a new scene of the game
   * @param _state The state of the scene
   * @param _scene The scene to register
   */
  void RegisterScene(SceneState _state, Scene* _scene);
  
  /**
   * @brief Changes the current scene and unloads the previous scene if present
   * @param _state The state of the scene to change into
   */
  void ChangeScene(SceneState _state);

  /**
   * @brief The main update method. This updates all the logic of the current scene
   */
  void Update();

  /**
   * @brief The main draw method. This updates all the render logic of the current scene
   */
  void Draw();

  /**
   * @brief Returns the state of the current scene
   * @return An enumerator representing the current state
   */
  SceneState GetCurrentState();

private:
  /**
   * @brief An unordered map containing all the registered scenes
   */
  std::unordered_map<SceneState, Scene*> m_mScenes;

  /**
   * @brief A pointer to the current scene
   */
  Scene* m_pCurrentScene;

  /**
   * @brief The current state of the scene.
   */
  SceneState m_eCurrentState;
};

