#include "TimerManager.h"
#include "utils/Utilities.h"

TimerManager::TimerManager()
{
  m_pLevelTimer = new Timer(12000.0f, 0.0f, true);
}

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

  if (!m_pLevelTimer->IsFinished())
  {
    m_pLevelTimer->m_fElapsed += m_fDeltaTime;
  }
  else
  {
    m_pLevelTimer->Reset();
  }
}

float TimerManager::GetDeltaTime() const
{
  return m_fDeltaTime;
}
