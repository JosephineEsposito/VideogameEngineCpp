#include "Timer.h"

Timer::Timer()
{
  m_fDuration = 0.0f;
  m_fElapsed = 0.0f;
  m_bIsActive = false;
}

Timer::Timer(float _duration, float _elapsed, bool _active)
{
  m_fDuration = _duration;
  m_fElapsed = _elapsed;
  m_bIsActive = _active;
}

bool Timer::IsFinished() const
{
  // we check if the timer ended
  return m_bIsActive && m_fElapsed >= m_fDuration;
}

void Timer::Reset()
{
  m_fElapsed = 0.0f;
  m_bIsActive = true;
}