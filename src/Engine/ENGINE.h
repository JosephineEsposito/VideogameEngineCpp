/*********************************************************
* The definition of the ENGINE
**********************************************************/
#pragma once

#include <memory>
#include <string>
#include <sstream>

#include "utils/Color.h"

class Tigr;
class Vec2;


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
  static void Log(std::string& _text);


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
  Tigr* getScreen() const;

  int GetWidth() const;

  int GetHeight() const;

  static ENGINE& GetInstance();
#pragma endregion

#pragma region | Setters
  /**
   * @brief To set the engine's window's size
   * @param _width 
   * @param _height 
   */
  void setWindowSize(int& _width, int& _height);

  /**
   * @brief To set the window's title
   * @param _title A string representing the title of the screen
   */
  void setWindowTitle(std::string& _title);

  /**
   * @brief To set the bakcground of the engine's window
   * @param _color 
   */
  void setBackgroundColor(Color& _color);
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

