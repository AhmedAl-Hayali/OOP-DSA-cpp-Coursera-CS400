#include <iostream>

using std::cout;
using std::endl;

int main() {
  int  i =  2,  j =  4,  k =  8;
  int *p = &i, *q = &j, *r = &k; // All memory is on the stack because the `new` keyword isn't used

  k = i; // k takes on the value of i, so k = 2 now
  cout << i << j << k << *p << *q << *r << endl; // 242242

  p = q; // p points to pointee of q, i.e. j, so p points to j
  cout << i << j << k << *p << *q << *r << endl; // 242442

  *q = *r; // dereferenced q takes on the value of dereferenced r, so j = k, and j = 2
  cout << i << j << k << *p << *q << *r << endl; // 222222

  return 0;
}
