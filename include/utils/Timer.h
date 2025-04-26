#pragma once
class Timer
{
public:
  Timer();
  Timer(float _duration, float _elapsed, bool _active);

  bool IsFinished() const;


  float duration;
  
  float elapsed;
  
  bool active;
};

