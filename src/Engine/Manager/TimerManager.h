/*********************************************************
* Handler of timer and score
**********************************************************/
#pragma once
class TimerManager
{
public:
  static TimerManager& GetInstance();

  void StartFrame();

  float GetDeltaTime() const;

  TimerManager(const TimerManager&) = delete;
  TimerManager& operator=(const TimerManager&) = delete;

private:
  float m_fDeltaTime = 0.0f;
  double m_dLastTime = 0.0f;

  TimerManager() {};
};

