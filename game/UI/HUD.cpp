#include "HUD.h"
#include "Engine/ENGINE.h"
#include "Engine/Manager/TimerManager.h"
#include "Engine/Manager/GameManager.h"
#include "utils/Utilities.h"


HUD::HUD()
{
  ENGINE::Log("HUD", "Constructor", "Constructor called.");
  textColor = Color();
  m_iTimer = 120;
  timerIcon = nullptr;
}

void HUD::Init()
{
  ENGINE::Log("HUD", "Init", "Initializing the object.");
  m_iTimer = 10; // in seconds

  textColor.SetColor(0xf2, 0xf2, 0xe9);

  timerIcon = new Sprite("assets/ui/timer.png");
}

void HUD::Update()
{
  // update text timer here
  m_iTimer = (int)(TimerManager::GetInstance().m_pLevelTimer->m_fElapsed);
}

void HUD::Draw()
{
  // we get the engine instance
  ENGINE& engine = ENGINE::GetInstance();

  // we set the timer position and draw
  Vec2 timerPos(engine.GetWidth() - 50, 20);
  engine.Print(utils::toString(m_iTimer), &timerPos, &textColor);
  // we get the score and draw
  Vec2 scorePos(engine.GetWidth() - 50, 40);
  engine.Print(utils::toString(GameManager::GetInstance().GetHighScore()), &scorePos, &textColor);

  // we draw the timer icon
  if (timerIcon)
  {
    timerIcon->Draw(engine.GetScreen(), engine.GetWidth() - 80, 16);
  }
}


void HUD::Unload()
{
  // we unload the scene
  ENGINE::Log("HUD", "Unload", "Unloading the object.");
  delete timerIcon;
  timerIcon = nullptr;
}
