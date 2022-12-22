#include <iostream>
#include <deque>
#include <defs.hpp>
#include <boost/gil.hpp>
#include <boost/gil/extension/io/png.hpp>

using namespace std;
using namespace boost::gil;

uint32_t findBestDivisor(uint64_t n);

int main() {
	INIT_BINARY_IO;
	
	INFO("Reading input");
	deque<unsigned char> input;
	int inp;
	while (true) {
		inp = cin.get();
		if (cin.eof()) break;
		input.push_back(inp);
	}
	
	INFO("Calculating");
	auto length = input.size();
	auto width = findBestDivisor(length);
	auto height = static_cast<uint32_t>(length / width);
	
	INFO("Creating image");
	gray8_image_t image{width, height};
	gray8_view_t imageView = view(image);
	
	INFO("Painting image");
	for (::uint32_t i = 0; i < height; i++) {
		for (::uint32_t j = 0; j < width; j++) {
			imageView(j, i) = input[i * width + j];
		}
	}
	
	INFO("Writing output");
	write_view(cout, imageView, png_tag());
	EXIT_OK;
}

uint32_t findBestDivisor(uint64_t n) {
	for (uint32_t i = floor(sqrt(n)); i > 1; i--) {
		if (n % i == 0) {
			return i;
		}
	}
	
	return 1;
}
