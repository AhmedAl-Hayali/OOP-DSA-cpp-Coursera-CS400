/**
 * C++ program using the Cube's one arugment constructor.
 * 
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#include "Cube.h"
#include <iostream>

int main() {
  uiuc::Cube c;  // !!! This is problematic because our implementation contains a custom constructor with 1 argument, length, whereas this usage expects a constructor without arguments.
  std::cout << "Volume: " << c.getVolume() << std::endl;
  return 0;
}
