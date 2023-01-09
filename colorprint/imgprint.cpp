// THIS CODE MAKES A *RAINBOW*
#include <iostream>
#include "imgprint.h"

using namespace std;

int main() {
    int x = 16;
    image img(x, x);
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