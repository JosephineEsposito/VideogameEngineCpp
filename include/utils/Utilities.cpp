// JOSEPHINE ESPOSITO
// 
// Implementation of the namespace Utilities

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

  void write_file(std::string data, std::string fileName)
  {
    std::ofstream out(fileName, std::ofstream::binary); // creating the file

    int size = data.size(); // obtainind the data size

    out.write(data.c_str(), size);  // writing into the file

    out.close();  // always close the ofstream after finishing writing
  }

}