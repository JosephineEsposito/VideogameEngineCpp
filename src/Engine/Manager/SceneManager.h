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
  SceneManager() = default;
  SceneManager(const SceneManager&) = delete;
  SceneManager& operator=(const SceneManager) = delete;

  static SceneManager& GetInstance();

  void RegisterScene(SceneState _state, Scene* _scene);
  
  void ChangeScene(SceneState _state);

  void Update();

  void Draw();

  SceneState GetCurrentState();

private:
  std::unordered_map<SceneState, Scene*> m_mScenes;
  Scene* m_pCurrentScene;
  SceneState m_eCurrentState = SceneState::INIT;
};

