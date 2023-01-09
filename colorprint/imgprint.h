#include <iostream>
#include <string>
#include <vector>
#include "colorprint.h"
using namespace std;

class image {
    private:
    int width = 0;
    int height = 0;
    vector<vector<pixel>> pixelArr;

    public:
    image(vector<vector<pixel>> pixelArr) {
        this->pixelArr = pixelArr;
        height = pixelArr.size();
        width = pixelArr[0].size();
    }
    image(size_t width, size_t height) {
        this->width = width;
        this->height = height;
        pixelArr.resize(height);
        for (size_t i = 0; i < height; i++) {
            pixelArr[i].resize(width);
        }
    }
    image write(int x, int y, pixel p) {
        pixelArr[y][x] = p;
        return *this;
    }
    friend ostream& operator<<(ostream& os, image& img) {
        for (size_t i = 0; i < img.pixelArr.size(); i++) {
            for (size_t j = 0; j < img.pixelArr[i].size(); j++) {
                os << img.pixelArr[i][j];
            }
            os << endl;
        }
        return os;
    }
    int get_width() { return width; }
    int get_height() { return height; }
};