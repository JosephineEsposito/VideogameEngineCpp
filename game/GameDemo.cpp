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
  // we get the engine instance
  ENGINE& engine = ENGINE::GetInstance();
  // we get the instnace of the scene manager
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
    // we start the frame and calculate delta time
    engine.BeginFrame();

    // update the current scene
    sceneManager.Update();
    // draw the current scene
    sceneManager.Draw();

    // we end the frame and update the logic of the engine
    engine.EndFrame();
  }
}
