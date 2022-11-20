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
  int *x = new int; // Heap memory contains integer, stack has int pointer
  int &y = *x; // y is a reference variable (or alias) to the dereferenced value of x, so now the heap memory contains int y
  y = 4; // Setting the heap memory content to 4

  cout << &x << endl; // Large number because it's pointer to stack
  cout << x << endl; // Small number because it's pointer to heap
  cout << *x << endl; // 4, this is just y

  cout << &y << endl; // Same small number as x, it's the same pointer to the heap
  cout << y << endl; // 4
  // cout << *y << endl; // y is not a pointer so we cannot dereference it, this would cause a compile error
// Error is: indirection requires pointer operand ('int' invalid)
  return 0;
}
