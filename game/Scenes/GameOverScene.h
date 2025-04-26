#pragma once

#include "utils/Scene.h"
#include "utils/Color.h"



class GameOverScene : public Scene
{
public:
  GameOverScene();

  void Init() override;

  void Update() override;

  void Draw() override;

  void Unload() override;

  SceneState m_eState;

private:
  Color background;
  Color textColor;

  const char* m_cTitle;
  const char* m_cSubtitle;
  const char* m_cScore;
};

