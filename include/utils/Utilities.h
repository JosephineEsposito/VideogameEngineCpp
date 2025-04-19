// JOSEPHINE ESPOSITO
// 
// Definition of the namespace Utilities:
// - time related functions
// - write and read to and from a file
//    + - the file must be of xml format data

#include <string>

namespace utils
{
  // Returns seconds
  double time_ss();

  // Method to pause the engine
  void wait(float _ms);

  // Method to write into a file
  void write_file(std::string data, std::string fileName);

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