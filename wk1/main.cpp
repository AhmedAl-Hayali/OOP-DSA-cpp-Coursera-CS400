#include <iostream>

int main() { // Start of program
	int i = 4; // Allocate i = 4 with type integer
	i = i + 2; // Make i = 6

	char c = 'a'; // Make the character with name c have value 'a'

	std::cout << i << " " << c << std::endl; // "console out", i.e. output to console the following: variable i, concatenated to it is a space, then c, then a newline character. expected output: 6 a

	return 0;
}
