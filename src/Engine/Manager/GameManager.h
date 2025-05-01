#pragma once

#include <string>

class GameManager
{
public:
  /**
   * @brief The default constructor
   */
  GameManager();

  /**
   * @brief The copy constructor. This has been disabled for it is a singleton
   * @param  The GameManager to copy
   */
  GameManager(const GameManager&) = delete;

  /**
   * @brief The assign and copy operator. This has been disabled for it is a singleton
   * @param  The GameManager to copy
   * @return The copied GameManager
   */
  GameManager& operator=(const GameManager&) = delete;

  /**
   * @brief Returns the instance of the GameManager
   * @return A reference of the static instance of the GameManager
   */
  static GameManager& GetInstance();

  /**
   * @brief Loads the highscore
   */
  void LoadScore();

  /**
   * @brief Saves the highscore
   */
  void SaveScore();

  /**
   * @brief Checks if the current gamescore is higher that the saved one
   * @return 
   */
  bool IsNewHighScore(float _score);

  /**
   * @brief Returns the current highscore
   * @return A float representing the score
   */
  float GetHighScore() const;

private:
  /**
   * @brief The score of the level
   */
  float m_fScore;
};

