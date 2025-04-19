/*********************************************************
* This is used only to setup the engine and call the game's main(init)
**********************************************************/

#include <iostream>

#include "Engine/ENGINE.h"

#include "Engine/Manager/SceneManager.h"

/**
 * @brief The entry point of the application.
   This will setup the engine and load the used files
 * @return An int representing the exit status of the application.
   -1 if an error occurred, 0 otherwise
 */
int main()
{
    std::cout << "Engine initialization!\n";

    // Engine initialization
    ENGINE engine;
    // Manager initialization
    SceneManager sceneManager;

    // we set the parameters of the engine's window
    std::string title = "Josephine Esposito";
    engine.setWindowTitle(title);
    int width = 600;
    int height = 400;
    engine.setWindowSize(width, height);


    // we initialize the engine and check if the process was successfull
    if (!engine.Init())
    {
      // if unable to initialize the engine, exit with a -1
      return -1;
    }


    // we load the assets to use here



    // this is the main loop of the engine
    while (engine.IsRunning())
    {
      engine.BeginFrame();

      sceneManager.Update();
      sceneManager.Draw();

      engine.EndFrame();
    }

    // after exiting the main loop we close the engine
    engine.Quit();

    return 0;
}

//EOF