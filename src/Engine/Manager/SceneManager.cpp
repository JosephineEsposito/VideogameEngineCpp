#include "SceneManager.h"

#include "Engine/ENGINE.h"

#include <iostream>

SceneManager& SceneManager::GetInstance()
{
  static SceneManager instance;
  return instance;
}


void SceneManager::RegisterScene(SceneState _state, Scene* _scene)
{
  m_mScenes[_state] = _scene;
}

void SceneManager::ChangeScene(SceneState _state)
{
  ENGINE::Log("SceneManager", "ChangeScene", "Changing the scene.");

  if (_state == m_eCurrentState)
  {
    ENGINE::Log("SceneManager", "ChangeScene", "Error: cannot change to the same scene.");
    return;
  }

  auto pair = m_mScenes.find(_state);
  if (pair == m_mScenes.end())
  {
    ENGINE::Log("SceneManager", "ChangeScene", "Error: Requested scene not found.");
    return;
  }

  if (m_pCurrentScene)
  {
    m_pCurrentScene->Unload();
  }

  m_pCurrentScene = pair->second;
  m_pCurrentScene->Init();
  m_eCurrentState = _state;
}


void SceneManager::Update()
{
  if (m_pCurrentScene)
  {
    m_pCurrentScene->Update();
  }
}

void SceneManager::Draw()
{
  if (m_pCurrentScene)
  {
    m_pCurrentScene->Draw();
  }
}

SceneState SceneManager::GetCurrentState()
{
  return m_eCurrentState;
}
