#include <iostream>
#include <deque>
#include <fstream>
#include <defs.hpp>
#include <boost/gil.hpp>
#include <boost/gil/extension/io/png.hpp>

using namespace std;
using namespace boost::gil;

int main() {
	INIT_BINARY_IO;
	// deque<unsigned char> input;
	// int inp;
	// while (true) {
	// 	inp = cin.get();
	// 	if (cin.eof()) break;
	// 	input.push_back(inp);
	// }
	
	INFO("Reading Image");
	gray8_image_t image;
	read_image("image.png", image, png_tag());
	gray8_view_t imageView = view(image);
	
	INFO("Writing File");
	ofstream outputFile{"file.exe", ios_base::binary};
	for (::uint32_t i = 0; i < image.height(); i++) {
		for (::uint32_t j = 0; j < image.width(); j++) {
			outputFile.put(reinterpret_cast<char&>(imageView(i, j)));
		}
	}
	outputFile.close();
	
	EXIT_OK;
}
