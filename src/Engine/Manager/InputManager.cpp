#include "InputManager.h"

#include "Engine/ENGINE.h"
#include "libs/tigr.h"


InputManager& InputManager::GetInstance()
{
  static InputManager instance;
  return instance;
}

void InputManager::Update()
{
  m_lPreviousKeys = m_lCurrentKeys;

  for (int key = 0; key < 256; ++key)
  {
    m_lCurrentKeys[key] = tigrKeyHeld(ENGINE::GetInstance().getScreen(), key);
  }
}

bool InputManager::IsKeyPressed(int _key)
{
  return m_lCurrentKeys[_key] && !m_lPreviousKeys[_key];
}

bool InputManager::IsKeyDown(int _key)
{
  return tigrKeyDown(ENGINE::GetInstance().getScreen(), _key);
}

bool InputManager::IsKeyReleased(int _key)
{
  return !m_lCurrentKeys[_key] && m_lPreviousKeys[_key];
}