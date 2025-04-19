/*********************************************************
* Handler of systems
**********************************************************/
#pragma once

#include <set>

#include "ECS/Entity.h"


class System
{
public:
  virtual ~System() = default;

  virtual void Update() = 0;

  virtual void Draw() = 0;

  virtual void RemoveEntity(Entity _entity) = 0;

  std::set<Entity> m_lEntities;
};

