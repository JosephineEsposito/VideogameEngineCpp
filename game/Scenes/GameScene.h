#pragma once

#include "utils/Scene.h"


class GameScene : public Scene
{
public:
  GameScene() = default;

  void Init() override;
  void Update() override;
  void Draw() override;
  void Unload() override;
};

