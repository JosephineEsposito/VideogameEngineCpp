#include "GameDemo.h"

#include <iostream>

#include "Engine/ENGINE.h"

// managers
#include "Engine/Manager/SceneManager.h"
#include "Engine/Manager/InputManager.h"

//scenes
#include "Scenes/MenuScene.h"
#include "Scenes/GameScene.h"
#include "Scenes/GameOverScene.h"



void GameDemo::Run()
{
  ENGINE& engine = ENGINE::GetInstance();
  SceneManager& sceneManager = SceneManager::GetInstance();

  // creating the scenes
  sceneManager.RegisterScene(SceneState::MENU, new MenuScene());
  sceneManager.RegisterScene(SceneState::PLAYING, new GameScene());
  sceneManager.RegisterScene(SceneState::GAMEOVER, new GameOverScene());

  // load the default scene
  sceneManager.ChangeScene(SceneState::PLAYING); //@review <- change this back to menu

  // main game loop
  while (engine.IsRunning())
  {
    engine.BeginFrame();

    // update the current scene
    sceneManager.Update();
    // draw the current scene
    sceneManager.Draw();

    engine.EndFrame();
  }
}
