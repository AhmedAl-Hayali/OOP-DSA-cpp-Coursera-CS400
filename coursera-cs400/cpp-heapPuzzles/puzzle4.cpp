/**
 * C++ puzzle program.  Try to figure out the result before running!
 * 
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#include <iostream>

using std::cout;
using std::endl;

int main() {
  int *x; // x is a pointer
  int size = 3;
  x = new int[size]; // x points to beginning of array on heap, size 3

  for (int i = 0; i < size; i++) { // iterating through array
    x[i] = i + 3; // setting array element i to be i + 3
  }
  // at this point, x = {3, 4, 5};

  delete[] x; // Removing 
}
