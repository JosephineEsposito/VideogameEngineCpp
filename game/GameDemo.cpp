#include "GameDemo.h"

#include <iostream>

#include "Engine/ENGINE.h"

// managers
#include "Engine/Manager/SceneManager.h"
#include "Engine/Manager/InputManager.h"

//scenes
#include "Scenes/MenuScene.h"
#include "Scenes/GameScene.h"



void GameDemo::Run()
{
  ENGINE& engine = ENGINE::GetInstance();
  SceneManager& sceneManager = SceneManager::GetInstance();

  // create scenes
  MenuScene* menuScene = new MenuScene();

  // load the default scene
  sceneManager.ChangeScene(menuScene);

  // main game loop
  while (engine.IsRunning())
  {
    engine.BeginFrame();

    // update the current scene
    sceneManager.Update();
    // draw the current scene
    sceneManager.Draw();

    // we check for input to change scene. We can only change scene if we are not already in it
    if (sceneManager.GetCurrentState() != SceneState::PLAYING && InputManager::GetInstance().IsKeyDown(TK_SPACE))
    {
      GameScene* gameScene = new GameScene();
      // we switch to the game scene
      puts("[GameDemo]\tPressed space");
      sceneManager.ChangeScene(gameScene);
    }


    engine.EndFrame();
  }
}
