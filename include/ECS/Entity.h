/*********************************************************
* Handler of entities. Handles ID and registration
**********************************************************/
#pragma once
#include <cstdint>
#include <queue>
#include <unordered_set>

/**
 * @brief The entity
 */
using Entity = std::uint32_t;
const Entity MAX_ENTITIES = 5000;

class EntityManager {
public:
  /**
   * @brief The default constructor
   */
  EntityManager();

  /**
   * @brief Creates a new entity
   * @return The newly created entity
   */
  Entity CreateEntity();

  /**
   * @brief Destroy an entity
   * @param _entity The enity to destroy
   */
  void DestroyEntity(Entity _entity);

  /**
   * @brief Checks if an netity is alive
   * @param _entity The entity to check
   * @return A bool representing if the entity is alive or not
   */
  bool IsEntityAlive(Entity _entity) const;

private:
  /**
   * @brief The queue of available entities
   */
  std::queue<Entity> m_lAvailableEntities;
  
  /**
   * @brief The set of alive entities
   */
  std::unordered_set<Entity> m_lLivingEntities;
};