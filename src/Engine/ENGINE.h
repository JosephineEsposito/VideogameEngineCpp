/*********************************************************
* The definition of the ENGINE
**********************************************************/
#pragma once


#include <string>
#include <sstream>

class Tigr;


class ENGINE
{
public:
#pragma region | Constructor and Destructor Methods
  /**
   * @brief The default constructor of the class
   */
  ENGINE();

  /**
   * @brief The default destructor of the class
   */
  ~ENGINE();
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

  /**
   * @brief Clears the screen of the engine
   */
  void Clear();

  
#pragma region | Main Loop
  /**
   * @brief Reads the inputs events in the engine
   * @return
   */
  bool Input();

  /**
   * @brief Renders images and more in the engine
   */
  void Render();
  
  /**
   * @brief Updates the logic of the engine
   */
  void Update();
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
  void Log(const char* _text);

  /**
   * @brief Logs the received information 
   * @param _text The string value to log
   */
  void Log(std::string& _text);


  /**
   * @brief Prints a text on the engine's window
   * @param _text The text to print on the screen
   * @param _r The red RGB color value of the text as hex
   * @param _g The green RGB color value of the text as hex
   * @param _b The blue RGB color value of the text as hex
   */
  void Print(const char* _text, unsigned char _r = 0xff, unsigned char _g = 0xff, unsigned char _b = 0xff);
  
  /**
   * @brief Prints a text on the engine's window
   * @param _text The text to print on the screen
   * @param _x The x coordinate for the placement of the text
   * @param _y The y coordinate for the placement of the text
   * @param _r The red RGB color value of the text as hex
   * @param _g The green RGB color value of the text as hex
   * @param _b The blue RGB color value of the text as hex
   */
  void Print(std::string& _text, int _x = 0, int _y = 0, unsigned char _r = 0xff, unsigned char _g = 0xff, unsigned char _b = 0xff);
#pragma endregion

#pragma region | Templates
  /**
   * @brief A method to convert any variable to string
   * @tparam T The template variable to convert to string
   * @param _t The variable to convert to string
   * @return The variable converted to string
   */
  template<typename T>
  std::string toString(const T& _t)
  {
    std::stringstream ss;
    ss << _t;
    return ss.str();
  }
#pragma endregion

#pragma region | Getters
  /**
   * @brief To get the delta time of the engine
   * @return A float representing the estimated delta time of the engine
   */
  float getDeltaTime() const;

  /**
   * @brief To get the window of the engine
   * @return A pointer to the engine's window
   */
  Tigr* getScreen() const;
#pragma endregion

  
#pragma region | Setters
  /**
   * @brief To start the delta time of the engine
   */
  void StartTime();

  /**
   * @brief To set the delta time of the engine
   */
  void setDeltaTime(float& _time);

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
#pragma endregion


private:

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
   * @brief The estimated delta time of the engine
   */
  float m_fDeltaTime;

  /**
   * @brief A pointer to the engine's window
   */
  Tigr* m_pScreen;
#pragma endregion
};

