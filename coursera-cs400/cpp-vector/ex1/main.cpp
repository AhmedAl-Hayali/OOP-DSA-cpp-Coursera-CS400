/**
 * C++ program using the std::vector class.
 * 
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#include <vector>
#include <iostream>

int main() {
  std::vector<int> v;
  v.push_back( 2 ); // v = [2]
  v.push_back( 3 ); // v = [2, 3]
  v.push_back( 5 ); // v = [2, 3, 5]

  std::cout << v[0] << std::endl; // 2
  std::cout << v[1] << std::endl; // 3
  std::cout << v[2] << std::endl; // 5

  return 0;
}
