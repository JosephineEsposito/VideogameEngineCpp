#include "PlayerSystem.h"

#include "Engine/ENGINE.h"
#include "Engine/Manager/TimerManager.h"

PlayerSystem::PlayerSystem()
{
  m_iDirection = 0;
  m_fSpeed = 150.0f;
}


void PlayerSystem::HandleInput(bool _leftPressed, bool _rightPressed)
{
  m_iDirection = 0;
  if (_leftPressed)
  {
    m_iDirection -= 1;
  }
  if (_rightPressed)
  {
    m_iDirection += 1;
  }
}


void PlayerSystem::Update()
{
  for (Entity entity : m_lEntities)
  {
    // we verify if the entity has a position component
    if (Coordinator::GetInstance().HasComponent<Position>(entity))
    {
      Position& position = Coordinator::GetInstance().GetComponent<Position>(entity);
      position.pos.x += m_fSpeed * m_iDirection * TimerManager::GetInstance().GetDeltaTime();

      // we limit its movement to the borders of the engine's window
      if (position.pos.x < 0)
      {
        position.pos.x = 0;
      }
      if (position.pos.x > ENGINE::GetInstance().GetWidth() - 32) //@review players sprite width
      {
        position.pos.x = ENGINE::GetInstance().GetWidth() - 32;
      }
    }
  }
}


void PlayerSystem::RemoveEntity(Entity _entity)
{
  Coordinator::GetInstance().m_pComponentManager->positions.erase(_entity);
  Coordinator::GetInstance().m_pComponentManager->velocities.erase(_entity);
  Coordinator::GetInstance().m_pComponentManager->sprites.erase(_entity);
}