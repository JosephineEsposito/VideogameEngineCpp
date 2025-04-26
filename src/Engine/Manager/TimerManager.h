/*********************************************************
* Handler of timer and score
**********************************************************/
#pragma once

#include <string>
#include <unordered_map>

#include "utils/Timer.h"


class TimerManager
{
public:
  static TimerManager& GetInstance();

  void StartFrame();

  float GetDeltaTime() const;

  TimerManager(const TimerManager&) = delete;
  TimerManager& operator=(const TimerManager&) = delete;

  void CreateTimer(const std::string& _name, float _durationInSeconds);

  void ResetTimer(const std::string& _name);

  bool IsTimerFinished(const std::string& _name) const;

  float GetTimerElapsed(const std::string& _name) const;

private:
  float m_fDeltaTime = 0.0f;
  double m_dLastTime = 0.0f;

  std::unordered_map<std::string, Timer> m_lTimers;

  TimerManager() {};
};

