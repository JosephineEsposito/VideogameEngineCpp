#pragma once

#include <string>

#include "utils/Scene.h"

#include "utils/Color.h"



class MenuScene : public Scene
{
public:
  MenuScene();

  void Init() override;

  void Update() override;

  void Draw() override;

  void Unload() override;

  SceneState m_eState;

private:
  Color* background;
  Color* textColor;

  const char* m_sTitle;
  const char* m_sText;

};

