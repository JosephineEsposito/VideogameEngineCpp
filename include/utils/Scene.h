#pragma once

#include "enums/SceneState.h"

class Scene
{
public:
  Scene(SceneState state) : m_eState(state) {} // costruttore che setta lo stato
  virtual ~Scene() {};

  virtual void Init() = 0;

  virtual void Update() = 0;

  virtual void Draw() = 0;

  virtual void Unload() = 0;

  SceneState m_eState = SceneState::INIT;

};

