/*********************************************************
* This creates and handles a timer
**********************************************************/
#pragma once
class Timer
{
public:
  /**
   * @brief The default constructor
   */
  Timer();

  /**
   * @brief The constructor of the timer
   * @param _duration The max duration of the timer in seconds
   * @param _elapsed The elapsed time. Default value is 0.0f
   * @param _active If the timer is active or not
   */
  Timer(float _duration, float _elapsed, bool _active);

  /**
   * @brief Checks if the timer has finished or not
   * @return A bool representing the state of the timer
   */
  bool IsFinished() const;

  /**
   * @brief Resets the elapsed time of the timer back to 0.0f
   */
  void Reset();

  /**
   * @brief The elapsed time value of the timer
   */
  float m_fElapsed;


private:
  /**
   * @brief The max duration of the timer
   */
  float m_fDuration;
 
  /**
   * @brief The state of the timer
   */
  bool m_bIsActive;
};

