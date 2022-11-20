#include <vector>

int main() {
  std::vector<char[256]> v;
  std::vector<double> u;
  std::vector<std::vector<int>> w;
//  std::vector q; // Problematic because it's a templated type but has no concrete definition
  return 0;
}
