/*********************************************************
* Handler of input events
**********************************************************/
#pragma once

class InputManager
{
public:
  /**
   * @brief The default constructor of the manager
   */
  InputManager() = default;

  /**
   * @brief The copy constructor of the manager. Deleted for this is a singleton
   * @param  The manager to copy
   */
  InputManager(const InputManager&) = delete;

  /**
   * @brief The assign and copy operator. Deleted for this is a singleton
   * @param  The manager to copy
   * @return The copied manager
   */
  InputManager& operator=(const InputManager) = delete;

  /**
   * @brief Returns the static instance of the manager
   * @return A reference to the static instance of the manager
   */
  static InputManager& GetInstance();


  /**
   * @brief Checks if the key has been pressed
   * @param _key The ASCII relative value of the key
   * @return A bool stating if the key has been pressed or not
   */
  bool IsKeyPressed(int _key);

  /**
   * @brief Checks if the key is being held down
   * @param _key The ASCII relative value of the key
   * @return A bool stating if the key is being held down
   */
  bool IsKeyDown(int _key);

};

