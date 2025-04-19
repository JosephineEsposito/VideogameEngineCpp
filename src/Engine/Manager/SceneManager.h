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
  void ChangeScene(Scene* _newScene);

  void PushScene(Scene* _newScene);

  void PopScene();

  void Update();

  void Draw();

private:
  std::stack<Scene*> m_lScenes;
};

