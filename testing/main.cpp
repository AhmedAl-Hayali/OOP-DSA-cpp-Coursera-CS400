#include <iostream>

int *allocate_an_integer() {
	int *i = new int;
	*i = 0;
	return i;
}

using std::cout;
using std::endl;

int main() {
	int *p = allocate_an_integer();
	cout << "address: " << p << ", dereferenced contents: " << *p << endl;
}
