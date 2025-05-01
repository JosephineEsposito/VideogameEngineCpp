/*********************************************************
* This is used only to setup the engine and launch the game demo
**********************************************************/

#include <iostream> // used for std::string

#include "Engine/ENGINE.h" // the engine
#include "game/GameDemo.h" // the game demo

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

  // setting the width of the game screen
  int width = 800;
  // setting the heigth of the game screen
  int heigth = 800;
  // setting the screen's title
  std::string title = "Demo";

  // setting the title value into the engine
  ENGINE::GetInstance().SetWindowTitle(title);
  // setting the screen size into the engine
  ENGINE::GetInstance().SetWindowSize(width, heigth);

  // checking if the engine has been initialized successfully
  if (!ENGINE::GetInstance().Init())
  {
    // if not we close the program and print a log
    ENGINE::Log("Program", "main", "Error: Unable to initialize the engine.");
    return -1;
  }
  
  // lauching the game here
  ENGINE::Log("Program", "main", "Launching the game.");
  // instancing the demo
  GameDemo demo;
  // launching the demo
  demo.Run();

  // after exiting the demo we print a log
  ENGINE::Log("Program", "main", "Closing the Engine.");
  // then we close the engine
  ENGINE::GetInstance().Quit();
  // and exit the program
  return 0;
}

//EOF