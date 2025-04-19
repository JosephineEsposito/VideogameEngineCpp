#include "SceneManager.h"

#include <iostream>

SceneManager& SceneManager::GetInstance()
{
  static SceneManager instance;
  return instance;
}

void SceneManager::ChangeScene(Scene* _newScene)
{
  std::cout << "[SceneManager] Trying to change scene" << std::endl;
  std::cout << "[SceneManager] Current state: " << (int)m_eCurrentState << std::endl;
  std::cout << "[SceneManager] New scene state: " << (int)_newScene->m_eState << std::endl;

  if (_newScene->m_eState == m_eCurrentState)
  {
    puts("[SceneManager]\tCannot change to the same scene.");
    return;
  }

  if (!m_lScenes.empty())
  {
    m_lScenes.top()->Unload();
    m_lScenes.pop();
  }

  m_lScenes.push(_newScene);
  m_lScenes.top()->Init();
  m_eCurrentState = m_lScenes.top()->m_eState;

  std::cout << "[SceneManager] New current state: " << (int)m_eCurrentState << std::endl;
}

void SceneManager::PushScene(Scene* _newScene)
{
  if (!m_lScenes.empty())
  {
    m_lScenes.top()->Unload();
  }

  m_lScenes.push(_newScene);
  m_lScenes.top()->Init();
  m_eCurrentState = m_lScenes.top()->m_eState;
}

void SceneManager::PopScene()
{
  if (!m_lScenes.empty())
  {
    m_lScenes.top()->Unload();
    m_lScenes.pop();
  }

  if (!m_lScenes.empty())
  {
    m_lScenes.top()->Init();
    m_eCurrentState = m_lScenes.top()->m_eState;
  }
}

void SceneManager::Update()
{
  if (!m_lScenes.empty())
  {
    m_lScenes.top()->Update();
  }
}

void SceneManager::Draw()
{
  if (!m_lScenes.empty())
  {
    m_lScenes.top()->Draw();
  }
}

SceneState SceneManager::GetCurrentState()
{
  return m_eCurrentState;
}
