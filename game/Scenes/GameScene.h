#pragma once

#include "utils/Scene.h"


class GameScene : public Scene
{
public:
  GameScene();

  void Init() override;
  void Update() override;
  void Draw() override;
  void Unload() override;

  SceneState m_eState;
};

