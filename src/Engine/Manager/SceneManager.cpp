#include "SceneManager.h"


void SceneManager::ChangeScene(Scene* _newScene)
{
  if (!m_lScenes.empty())
  {
    m_lScenes.top()->Unload();
    m_lScenes.pop();
  }

  m_lScenes.push(_newScene);
  m_lScenes.top()->Init();
}

void SceneManager::PushScene(Scene* _newScene)
{
  if (!m_lScenes.empty())
  {
    m_lScenes.top()->Unload();
  }

  m_lScenes.push(_newScene);
  m_lScenes.top()->Init();
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
