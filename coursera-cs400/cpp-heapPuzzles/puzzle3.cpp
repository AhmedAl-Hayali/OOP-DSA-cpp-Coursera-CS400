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
  int *p, *q; // 2 pointers on the stack
  p = new int; // p now points to somewhere in heap memory
  q = p; // q now points to the same place in heap memory
  *q = 8; // Dereferenced value of q, i.e. place in heap memory, now has value 8
  cout << *p << endl; // Dereferenced value of p is 8

  q = new int; // q now points to a different place in heap memory
  *q = 9; // Dereferenced value of q is 9, so new place in heap memory has value 9 
  cout << *p << endl; // 8
  cout << *q << endl; // 9

  return 0;
}
