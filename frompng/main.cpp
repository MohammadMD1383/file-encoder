#include <iostream>
#include <fstream>
#include <defs.hpp>
#include <boost/gil.hpp>
#include <boost/gil/extension/io/png.hpp>

using namespace std;
using namespace boost::gil;

int main() {
	INIT_BINARY_IO;
	
	INFO("Reading input");
	gray8_image_t image;
	read_image(cin, image, png_tag());
	gray8_view_t imageView = view(image);
	
	INFO("Writing output");
	for (::uint32_t i = 0; i < image.height(); i++) {
		for (::uint32_t j = 0; j < image.width(); j++) {
			cout.put(reinterpret_cast<char &>(imageView(j, i)));
		}
	}
	
	EXIT_OK;
}
