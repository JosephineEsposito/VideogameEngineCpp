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
  puts("[Program|main]\t\tEngine initialization.");

  int width = 800;
  int heigth = 800;
  std::string title = "Demo";

  ENGINE::GetInstance().setWindowTitle(title);
  ENGINE::GetInstance().setWindowSize(width, heigth);

  if (!ENGINE::GetInstance().Init())
  {
    ENGINE::Log("Program", "main", "Error: Unable to initialize the engine.");
    return -1;
  }
  
  // lauching the game here
  ENGINE::Log("Program", "main", "Launching the game.");
  GameDemo demo;
  demo.Run();

  ENGINE::Log("Program", "main", "Closing the Engine.");
  ENGINE::GetInstance().Quit();
  return 0;
}

//EOF
