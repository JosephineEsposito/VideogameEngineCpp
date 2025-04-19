/*********************************************************
* Handler of input events
**********************************************************/
#pragma once

#include <unordered_map>

#include "libs/tigr.h"


class InputManager
{
public:
  InputManager() {};
  InputManager(const InputManager&) = delete;
  InputManager& operator=(const InputManager) = delete;

  static InputManager& GetInstance();

  void Update();


  bool IsKeyPressed(int _key);

  bool IsKeyDown(int _key);

  bool IsKeyReleased(int _key);

private:
  std::unordered_map<int, bool> m_lCurrentKeys;
  std::unordered_map<int, bool> m_lPreviousKeys;
};

