/*********************************************************
* The definition of the namespace Utilities:
* - time related functions
* - write and read to and from a file
* --+ the file must be of xml format data
**********************************************************/
#include <string>
#include <sstream>

namespace utils
{
  /**
   * @brief Returns the time in seconds
   * @return A double representing the seconds
   */
  double time_ss();

  /**
   * @brief Pauses the engine
   * @param _ms The milliseconds to wait before unpausing
   */
  void wait(float _ms);

  /**
   * @brief Writes into an xml file
   * @param data The data to write
   * @param fileName The name of the file
   */
  void write_file_xml(std::string data, std::string fileName);

  /**
   * @brief Writes into a file
   * @param data The data to write
   * @param fileName The name of the file
   */
  void write_file(std::string data, std::string fileName);

  /**
   * @brief Reads a file
   * @param fileName The name of the file
   * @return The data string
   */
  std::string read_file(std::string fileName);

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

}

//EOF