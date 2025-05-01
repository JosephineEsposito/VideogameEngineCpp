/*********************************************************
* Handler of timer and score
**********************************************************/
#pragma once

#include "utils/Timer.h"

class TimerManager
{
public:
  /**
   * @brief The default constructor
   */
  TimerManager();

  /**
   * @brief The copy constructor. This has been disabled for it is a singleton
   * @param  The TimerManager to copy
   */
  TimerManager(const TimerManager&) = delete;

  /**
   * @brief The assign and copy operator. This has been disabled for it is a singleton
   * @param  The TimerManager to copy
   * @return The copied TimerManager
   */
  TimerManager& operator=(const TimerManager&) = delete;
  
  /**
   * @brief Returns the instance of the TimerManager
   * @return A reference of the static instance of the TimerManager
   */
  static TimerManager& GetInstance();

  /**
   * @brief Calculates and updates the delta time of the engie. Call this on the beginning of the main loop.
   */
  void StartFrame();

  /**
   * @brief Returns the current delta time
   * @return A float representing the delta time
   */
  float GetDeltaTime() const;


  Timer* m_pLevelTimer;

private:
  /**
   * @brief The delta time of the engine
   */
  float m_fDeltaTime = 0.0f;

  /**
   * @brief The previous time of the engine. This is used to calculate the delta time
   */
  double m_dLastTime = 0.0f;

};

