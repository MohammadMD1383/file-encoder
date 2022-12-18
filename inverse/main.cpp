/**
 * Inverses the bits of the data got from `cin` and outputs to `cout`
 * 10110110 => 01001001
 */

#include <iostream>
#include <defs.hpp>

using namespace std;

int main() {
	INIT_BINARY_IO;
	
	int i;
	while (true) {
		i = cin.get();
		if (cin.eof()) break;
		cout << static_cast<unsigned char>(~static_cast<unsigned char>(i));
	}
	
	EXIT_OK;
}
