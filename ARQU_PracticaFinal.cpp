/*********************************************************
* This is used only to setup the engine and call the game's main(init)
**********************************************************/

#include <iostream>

#include "Engine/ENGINE.h"
#include "game/GameDemo.h"

/**
 * @brief The entry point of the application.
   This will setup the engine and load the used files
 * @return An int representing the exit status of the application.
   -1 if an error occurred, 0 otherwise
 */
int main()
{
  // we set the engines properties here
  puts("[main]\tEngine initialization.");

  int width = 800;
  int heigth = 600;
  std::string title = "Demo";

  ENGINE::GetInstance().setWindowTitle(title);
  ENGINE::GetInstance().setWindowSize(width, heigth);

  if (!ENGINE::GetInstance().Init())
  {
    puts("[main]\tError: Unable to initialize the engine :(");
    return -1;
  }
  
  // lauching the game here
  puts("[main]\tLaunching the game.");
  GameDemo demo;
  demo.Run();

  puts("[main]\tClosing the Engine.");
  ENGINE::GetInstance().Quit();
  return 0;
}

//EOF

/*
    // SceneManager initialization
    std::cout << "SceneManager initialization!\n";
    SceneManager sceneManager;


    // we load the assets to use here

    // this is the main loop of the engine
    while (engine.IsRunning())
    {
      engine.BeginFrame();

      sceneManager.Update();
      sceneManager.Draw();

      engine.EndFrame();
    }
*/