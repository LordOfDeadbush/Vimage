// g++ png.cpp lodepng.cpp -Wall -Wextra -pedantic -ansi -O3
// use this to compile

#include "lodepng.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    const char *filename = argc > 1 ? argv[1] : "png.png";

    // load and decode
    std::vector<unsigned char> image;
    unsigned width, height;
    unsigned error = lodepng::decode(image, width, height, filename);

    for (int i = 0; i < image.size(); i++)
    {
        cout << (int)image[i] << " ";
    }

    // if there's an error, display it
    if (error)
        std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;

    // the pixels are now in the vector "image", 4 bytes per pixel, ordered RGBARGBA..., use it as texture, draw it, ...
}
