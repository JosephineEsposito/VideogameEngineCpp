/*********************************************************
* Handler of scenes
**********************************************************/
#pragma once

#include <memory>
#include <stack>

#include "utils/Scene.h"
#include "enums/SceneState.h"

class SceneManager
{
public:
  SceneManager() = default;
  SceneManager(const SceneManager&) = delete;
  SceneManager& operator=(const SceneManager) = delete;

  static SceneManager& GetInstance();

  void ChangeScene(Scene* _newScene);

  void PushScene(Scene* _newScene);

  void PopScene();

  void Update();

  void Draw();

  SceneState GetCurrentState();

private:
  std::stack<Scene*> m_lScenes;
  SceneState m_eCurrentState = SceneState::INIT;
};

