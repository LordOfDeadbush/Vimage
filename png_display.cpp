#include "lodepng/pngreader.h"
#include "colorprint/imgprint.h"

// g++ png_display.cpp lodepng.cpp -Wall -Wextra -pedantic -ansi -O3

using namespace std;

int main(int argc, char** argv) {
    const char *filename = argc > 1 ? argv[1] : "lodepng/png.png";
    int width, height;
    vector<int> png_vector = loadPng(filename, width, height);
    image img(width, height);
    for (size_t i = 0; i < img.get_height(); i++) {
        for (size_t j = 0; j < img.get_width(); j++) {
            int r = png_vector[4 * (i * img.get_width() + j)];
            int g = png_vector[4 * (i * img.get_width() + j) + 1];
            int b = png_vector[4 * (i * img.get_width() + j) + 2];
            int h = png_vector[4 * (i * img.get_width() + j) + 3];
            // cout << r << " " << g << " " << b << " " << h << endl;
            img.write(j, i, pixel(r, g, b, h));
        }
    }
    cout << img << endl;
    return 0;
}