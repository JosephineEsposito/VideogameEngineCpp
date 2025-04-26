#include "HUD.h"

#include "Engine/ENGINE.h"

#include "Engine/Manager/TimerManager.h"

#include "utils/Utilities.h"


HUD::HUD()
{
  ENGINE::Log("HUD", "Constructor", "Constructor called.");
  textColor = Color();
  m_iTimer = 120;
  m_iHealth = 10;
}

void HUD::Init()
{
  ENGINE::Log("HUD", "Init", "Initializing the object.");
  m_iTimer = 10; // in seconds

  m_iHealth = 1; // one chance

  textColor.setColor(0xf2, 0xf2, 0xe9);

  timerIcon = new Sprite("assets/ui/timer.png");
}

void HUD::Update()
{
  // update text timer here
  m_iTimer = (int)(120.0f - TimerManager::GetInstance().GetTimerElapsed("LevelTimer"));
}

void HUD::Draw()
{
  ENGINE& engine = ENGINE::GetInstance();

  Vec2 timerPos(engine.GetWidth() - 50, 20);
  engine.Print(utils::toString(m_iTimer), &timerPos, &textColor);

  if (timerIcon)
  {
    timerIcon->Draw(engine.getScreen(), engine.GetWidth() - 80, 16);
  }
}


void HUD::Unload()
{
  ENGINE::Log("HUD", "Unload", "Unloading the object.");
  delete timerIcon;
  timerIcon = nullptr;
}
