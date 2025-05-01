#include "GameManager.h"

#include <iostream>
#include <sstream>

#include "utils/Utilities.h"

#define HIGHSCORE_FILENAME "saves/hiscore.txt"


GameManager::GameManager()
{
  m_fScore = 0.0f;
  LoadScore();
}

GameManager& GameManager::GetInstance()
{
  static GameManager instance;
  return instance;
}


void GameManager::LoadScore()
{
  std::string sScore = utils::read_file(HIGHSCORE_FILENAME);

  if (!sScore.empty())
  {
    try
    {
      m_fScore = std::stof(sScore);
    }
    catch (const std::invalid_argument& e)
    {
      std::cerr << "Error: content non convertible to float";
      m_fScore = 0.0f;
    }
  }
  else
  {
    m_fScore = 0.0f; // no file found or error reading
  }
}

void GameManager::SaveScore()
{
  utils::write_file(utils::toString(m_fScore), HIGHSCORE_FILENAME);
}

bool GameManager::IsNewHighScore(float _score)
{
  if (_score > m_fScore)
  {
    m_fScore = _score;
    SaveScore();
    return true;
  }
  return false;
}

float GameManager::GetHighScore() const
{
  return m_fScore;
}