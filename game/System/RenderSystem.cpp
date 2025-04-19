#include "RenderSystem.h"


void RenderSystem::Draw()
{
  for (Entity entity : m_lEntities)
  {
    if (Coordinator::GetInstance().HasComponent<Sprite>(entity))
    {
      Sprite& sprite = Coordinator::GetInstance().GetComponent<Sprite>(entity);
      sprite.Draw(ENGINE::GetInstance().getScreen());
    }
  }
}

void RenderSystem::RemoveEntity(Entity _entity)
{
  m_lEntities.erase(_entity);
}