#include "TimerManager.h"
#include "utils/Utilities.h"

TimerManager& TimerManager::GetInstance()
{
  static TimerManager instance;
  return instance;
}

void TimerManager::StartFrame()
{
  double now = utils::time_ss();
  m_fDeltaTime = now - m_dLastTime;
  m_dLastTime = now;
}

float TimerManager::GetDeltaTime() const
{
  return m_fDeltaTime;
}
