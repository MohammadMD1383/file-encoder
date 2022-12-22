#include <iostream>
#include <deque>
#include <defs.hpp>
#include <boost/gil.hpp>
#include <boost/gil/extension/io/png.hpp>

using namespace std;
using namespace boost::gil;

deque<uint32_t> findDivisors(uint64_t n);

int main() {
	deque<unsigned char> input;
	int i;
	while (true) {
		i = cin.get();
		if (cin.eof()) break;
		input.push_back(i);
	}
	
	auto length = input.size();
	auto divisors = findDivisors(length);
	auto width = divisors[divisors.size() / 2];
	auto height = static_cast<int64_t>(length / width);
	
	gray8_image_t image{width, height};
	gray8_view_t imageView = view(image);
	
	for (int64_t p = 0; p < length; p++) {
		imageView(p % width, p / width) = input[p];
	}
	
	write_view("image.png", imageView, png_tag());
	EXIT_OK;
}

deque<uint32_t> findDivisors(uint64_t n) {
	deque<uint32_t> divisors;
	
	for (uint32_t i = 1; i <= sqrt(n); i++) {
		if (n % i == 0) {
			if (n / i == i) {
				divisors.push_back(i);
			} else {
				divisors.push_back(i);
				divisors.push_back(n / i);
			}
		}
	}
	
	return divisors;
}
