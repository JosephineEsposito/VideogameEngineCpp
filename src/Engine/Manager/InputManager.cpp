#include "InputManager.h"

#include "Engine/ENGINE.h"
#include "libs/tigr.h"


InputManager& InputManager::GetInstance()
{
  static InputManager instance;
  return instance;
}


bool InputManager::IsKeyPressed(int _key)
{
  return tigrKeyHeld(ENGINE::GetInstance().GetScreen(), _key);
}

bool InputManager::IsKeyDown(int _key)
{
  return tigrKeyDown(ENGINE::GetInstance().GetScreen(), _key);
}
