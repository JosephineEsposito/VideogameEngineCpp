#include "libs/tigr.h"   // Tigr
#include <string>        // string
#include <fstream>       // ofstream, ifstream, fstream | file management

namespace utils
{

  double time_ss()
  { // tigrTime() returns the time in seconds
    static double t = 0;
    t += tigrTime();
    return t;
  }

  void wait(float _ms)
  {
    float then = time_ss();
    do
    {
      float now = time_ss();
      float dt = now - then;
      then = now;
      _ms -= dt * 1000;
    } while (_ms > 0);
  }

  void write_file_xml(std::string data, std::string fileName)
  {
    std::ofstream out(fileName, std::ofstream::binary); // creating the file

    int size = data.size(); // obtainind the data size

    out.write(data.c_str(), size);  // writing into the file

    out.close();  // always close the ofstream after finishing writing
  }

  void write_file(std::string data, std::string fileName)
  {
    std::ofstream outFile(fileName);
    
    if (!outFile)
    {
      puts("Error: Unable to open the file to write");
      return;
    }

    outFile << data;
    outFile.close();
  }

  std::string read_file(std::string fileName)
  {
    std::ifstream inFile(fileName);

    if (!inFile)
    {
      puts("Error: Unable to open the file to read");
      return "";
    }

    std::string data((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());

    inFile.close();
    return data;
  }

}