#include "Timer.h"

Timer::Timer()
{
  duration = 0.0f;
  elapsed = 0.0f;
  active = false;
}

Timer::Timer(float _duration, float _elapsed, bool _active)
{
  duration = _duration;
  elapsed = _elapsed;
  active = _active;
}

bool Timer::IsFinished() const
{
  return active && elapsed >= duration;
}