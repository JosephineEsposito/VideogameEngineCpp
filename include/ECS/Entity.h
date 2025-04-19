/*********************************************************
* Handler of entities. Handles ID and registration
**********************************************************/
#pragma once
#include <cstdint>
#include <queue>
#include <unordered_set>

using Entity = std::uint32_t;
const Entity MAX_ENTITIES = 5000;

class EntityManager {
public:
  EntityManager();

  Entity CreateEntity();

  void DestroyEntity(Entity _entity);

  bool IsEntityAlive(Entity _entity) const;

private:
  std::queue<Entity> m_lAvailableEntities;
  
  std::unordered_set<Entity> m_lLivingEntities;
};