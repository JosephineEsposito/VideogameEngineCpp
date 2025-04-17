// JOSEPHINE ESPOSITO
// 
// Definition of the namespace Utilities:
// - time related functions
// - write and read to and from a file
//    + - the file must be of xml format data

namespace utils
{
  // Returns seconds
  double time_ss();

  // Method to pause the engine
  void wait(float _ms);

  // Method to write into a file
  void write_file(std::string data, std::string fileName);

}

//EOF