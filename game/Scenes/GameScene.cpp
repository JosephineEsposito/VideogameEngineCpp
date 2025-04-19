#include "GameScene.h"
#include "Engine/ENGINE.h"


GameScene::GameScene() : Scene(SceneState::PLAYING)
{
  // we set the scene state
  m_eState = SceneState::PLAYING;
}

void GameScene::Init()
{
  //inizializza sistema ecs, carica livelli, etc.
}

void GameScene::Update()
{
  // esegui logica, chiama gli update di ecs, etc.
}

void GameScene::Draw()
{
  // esegui render, chiama i render di ecs, etc.
}

void GameScene::Unload()
{
  // pulisci le risorse se serve
}

