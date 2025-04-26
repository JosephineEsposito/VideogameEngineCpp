#include "CollisionSystem.h"

#include "ECS/Coordinator.h"
#include "Engine/ENGINE.h"
#include "Engine/Manager/TimerManager.h"

CollisionSystem::CollisionSystem()
{ }

void CollisionSystem::Update()
{
  for (auto _aEntity = m_lEntities.begin(); _aEntity != m_lEntities.end(); ++_aEntity)
  {
    Entity aEntity = *_aEntity;

    if (!Coordinator::GetInstance().HasComponent<Position>(aEntity) || !Coordinator::GetInstance().HasComponent<SpriteComponent>(aEntity))
    {
      continue;
    }

    for (auto _bEntity = std::next(_aEntity); _bEntity != m_lEntities.end(); ++_bEntity)
    {
      Entity bEntity = *_bEntity;

      if (!Coordinator::GetInstance().HasComponent<Position>(bEntity) || !Coordinator::GetInstance().HasComponent<SpriteComponent>(bEntity))
      {
        continue;
      }

      if (CheckCollision(aEntity, bEntity))
      {
        ENGINE::Log("Collision detected between %d and %d\n");
        //@review -> aggiungi logica di risposta alla collisione
      }
    }
  }
}

void CollisionSystem::RemoveEntity(Entity _entity)
{
  m_lEntities.erase(_entity);
}

bool CollisionSystem::CheckCollision(Entity _aEntity, Entity _bEntity)
{
  Position& aPos = Coordinator::GetInstance().GetComponent<Position>(_aEntity);
  SpriteComponent& aSprite = Coordinator::GetInstance().GetComponent<SpriteComponent>(_aEntity);

  Position& bPos = Coordinator::GetInstance().GetComponent<Position>(_bEntity);
  SpriteComponent& bSprite = Coordinator::GetInstance().GetComponent<SpriteComponent>(_bEntity);

  // Carica temporaneamente i dati della texture
  Sprite aTempSprite(aSprite.textureName.c_str());
  Sprite bTempSprite(bSprite.textureName.c_str());

  return (
    aPos.pos.x < bPos.pos.x + bTempSprite.texture->w &&
    aPos.pos.x + aTempSprite.texture->w > bPos.pos.x &&
    aPos.pos.y < bPos.pos.y + bTempSprite.texture->h &&
    aPos.pos.y + aTempSprite.texture->h > bPos.pos.y
    );
}
