/*********************************************************
* The definition of the ENGINE
**********************************************************/
#pragma once

#include <string> // used for the logs and prints

#include "utils/Color.h" // used to define the background of the screen

class Tigr;
class Vec2; // used for positions


class ENGINE
{
public:

#pragma region | Constructor and Destructor Methods
  /**
   * @brief The default constructor of the class
   */
  ENGINE();

  /**
   * @brief The Copy constructor of the class
   * @param The engine object
   */
  ENGINE(const ENGINE&) = delete;

  /**
   * @brief The default destructor of the class
   */
  ~ENGINE();
#pragma endregion

#pragma region | Operators
  /**
   * @brief The assign and copy operator removed to prevent more than one instances of the engine at the time
   * @param  The engine to copy
   * @return A copy of the engine
   */
  ENGINE& operator=(const ENGINE) = delete;
#pragma endregion

#pragma region | Initialization
  /**
   * @brief Initializes the engine
   * @return A boolean value representing if the initialization was successfull
   */
  bool Init();

  /**
   * @brief Quits the engine
   * @return 
   */
  bool Quit();
#pragma endregion

  
#pragma region | Main Loop
  /**
   * @brief Called on the first frame, updates the input and the delta time
   */
  void BeginFrame();

  /**
   * @brief Updates the logic of the engine
   */
  void EndFrame();
  
#pragma endregion
  
#pragma region | Check methods
  /**
   * @brief Checks if the engine is currently running or not
   * @return A boolean value stating the current status of the engine
   */
  bool IsRunning();
#pragma endregion

#pragma region | Logs and Prints
  /**
   * @brief Logs the received information
   * @param _text The const char* to log
   */
  static void Log(const char* _text);

  /**
   * @brief Logs the received information 
   * @param _text The string value to log
   */
  static void Log(const char* _class, const char* _method, const char* _message);


  /**
   * @brief Prints a text on the engine's window
   * @param _text The text to print on the screen
   * @param _color The color value of the text
   */
  void Print(const char* _text, Color* _color);
  
  /**
   * @brief Prints a text on the engine's window
   * @param _text The text to print on the screen
   * @param _pos The vector 2 position for the placement of the text
   * @param _color The color value of the text
   */
  void Print(std::string _text, Vec2* _pos, Color* _color);
#pragma endregion


#pragma region | Getters
  /**
   * @brief To get the window of the engine
   * @return A pointer to the engine's window
   */
  Tigr* GetScreen() const;

  /**
   * @brief To get the width of the screen
   * @return An int representing the width of the screen
   */
  int GetWidth() const;

  /**
   * @brief To get the height of the screen
   * @return An int representing the height of the screen
   */
  int GetHeight() const;

  /**
   * @brief Returns the instance of the engine
   * @return A reference of the instance of the engine
   */
  static ENGINE& GetInstance();
#pragma endregion

#pragma region | Setters
  /**
   * @brief To set the engine's window's size
   * @param _width A reference of the window's width
   * @param _height A reference of the window's height
   */
  void SetWindowSize(const int& _width, const int& _height);

  /**
   * @brief To set the window's title
   * @param _title A string representing the title of the screen
   */
  void SetWindowTitle(const std::string& _title);

  /**
   * @brief To set the bakcground of the engine's window
   * @param _color A Color object containing the background color of the screen
   */
  void SetBackgroundColor(const Color& _color);
#pragma endregion


private:
  /**
   * @brief Clears the screen of the engine
   */
  void Clear();


#pragma region | Variables
  /**
   * @brief To check if the engine is currently running
   */
  bool m_bIsRunning;

  /**
   * @brief The window's title
   */
  const char* m_cTitle;

  /**
   * @brief The width of the window of the engine
   */
  int m_iScreenWidth;

  /**
   * @brief The height of the window of the engine
   */
  int m_iScreenHeight;

  /**
   * @brief A pointer to the engine's window
   */
  Tigr* m_pScreen;

  /**
   * @brief The background color of the engine
   */
  Color m_BackgroundColor;

#pragma endregion

};

