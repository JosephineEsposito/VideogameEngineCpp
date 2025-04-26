#pragma once

#include "utils/Color.h"
#include "utils/Vec2.h"
#include "utils/Sprite.h"

class HUD
{
public:
  HUD();

  void Init();

  void Update();

  void Draw();

  void Unload();

private:
  int m_iTimer;

  int m_iHealth;

  Color textColor;

  Sprite* timerIcon;
};

