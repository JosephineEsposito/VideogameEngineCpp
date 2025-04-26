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

  for (auto& pair : m_lTimers)
  {
    if (pair.second.active && !pair.second.IsFinished())
    {
      pair.second.elapsed += m_fDeltaTime;
    }
  }
}

float TimerManager::GetDeltaTime() const
{
  return m_fDeltaTime;
}

void TimerManager::CreateTimer(const std::string& _name, float _durationInSeconds)
{
  m_lTimers[_name] = Timer(_durationInSeconds, 0.0f, true);
}

void TimerManager::ResetTimer(const std::string& _name)
{
  if (m_lTimers.find(_name) != m_lTimers.end())
  {
    m_lTimers[_name].elapsed = 0.0f;
    m_lTimers[_name].active = true;
  }
}

bool TimerManager::IsTimerFinished(const std::string& _name) const
{
  auto timer = m_lTimers.find(_name);
  return timer != m_lTimers.end() ? timer->second.IsFinished() : false;
}

float TimerManager::GetTimerElapsed(const std::string& _name) const
{
  auto timer = m_lTimers.find(_name);
  return timer != m_lTimers.end() ? timer->second.elapsed : 0.0f;
}
