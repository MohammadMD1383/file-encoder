/**
 * Reverses contents of `cin` and outputs to `cout`
 * `b` -> reverses all bits: 10101111 11001100 => 00110011 11110101
 * `B` -> reverse only bytes: 10101111 11001100 => 11001100 10101111
 */

#include <iostream>
#include <deque>
#include <defs.hpp>
#include <cstring>
#include <boost/filesystem/path.hpp>

using namespace std;
using boost::filesystem::path;

unsigned char reverseBits(unsigned char c);

int main(int argc, char *argv[]) {
	INIT_BINARY_IO;
	
	if (argc > 2) {
		ERROR("Only one parameter may be specified, and must be 'b' or 'B'");
		EXIT_INVALID_PARAM_NUMBER;
	}
	
	bool bitReverse = false;
	if (argc == 2) {
		if (::strcmp("b", argv[1]) == 0)
			bitReverse = true;
		else if (::strcmp("B", argv[1]) != 0) {
			ERROR("Invalid parameter specified; Must be 'B' or 'b'");
			EXIT_INVALID_PARAM;
		}
	}
	
	deque<unsigned char> input;
	int i;
	while (true) {
		i = cin.get();
		if (cin.eof()) break;
		input.push_front(i);
	}
	
	for (const auto &b: input)
		cout << (!bitReverse ? b : reverseBits(b));
	
	EXIT_OK;
}

unsigned char reverseBits(unsigned char c) {
	c = (c & 0xF0) >> 4 | (c & 0x0F) << 4;
	c = (c & 0xCC) >> 2 | (c & 0x33) << 2;
	c = (c & 0xAA) >> 1 | (c & 0x55) << 1;
	return c;
}
