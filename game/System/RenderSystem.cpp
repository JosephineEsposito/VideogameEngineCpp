#include "RenderSystem.h"


void RenderSystem::Draw()
{
  for (Entity entity : m_lEntities)
  {
    if (Coordinator::GetInstance().HasComponent<SpriteComponent>(entity))
    {
      SpriteComponent& sprite = Coordinator::GetInstance().GetComponent<SpriteComponent>(entity);
      //sprite.sprite.Draw(ENGINE::GetInstance().getScreen());
    }
  }
}

void RenderSystem::RemoveEntity(Entity _entity)
{
  m_lEntities.erase(_entity);
}