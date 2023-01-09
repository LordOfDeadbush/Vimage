#include <iostream>
#include "colorprint.h"
using namespace std;

int main() {
    pixel b(0, 0, 0);
    pixel y(255, 0, 0);
    cout << b << b << b << y << b << b << b << endl;
    cout << b << b << y << y << y << b << b << endl;
    cout << b << b << y << y << y << b << b << endl;
    cout << b << b << y << y << y << b << b << endl;
    cout << b << b << y << y << y << b << b << endl;
    cout << b << b << y << y << y << b << b << endl;
    cout << b << y << y << y << y << y << b << endl;
    cout << y << y << y << y << y << y << y << endl;
    return 0;
}