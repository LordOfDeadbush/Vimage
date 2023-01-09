#include <iostream>
// #include "colorprint.h"
#include "imgprint.h"

using namespace std;

int main() {
    image img(64, 64);
    for (size_t i = 0; i < img.get_height(); i++) {
        for (size_t j = 0; j < img.get_width(); j++) {
            int r = (img.get_height() - i) * 255 / img.get_height();
            int g = (img.get_width() - j) * 255 / img.get_width();
            img.write(j, i, pixel(r, g, 0));
        }
    }
    cout << img << endl;
    return 0;
}