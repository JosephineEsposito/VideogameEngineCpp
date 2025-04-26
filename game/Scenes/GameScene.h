#pragma once

#include "utils/Scene.h"
#include "utils/Sprite.h"

#include "ECS/Entity.h"
#include "ECS/Component.h"
#include "ECS/Coordinator.h"

#include "UI/HUD.h"


class GameScene : public Scene
{
public:
  GameScene();

  void Init() override;
  void Update() override;
  void Draw() override;
  void Unload() override;

  SceneState m_eState;

private:
  HUD m_hud;

  Entity player;

  Sprite* map;
};

