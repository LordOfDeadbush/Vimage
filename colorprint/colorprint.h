#include <iostream>
#include <string>
using namespace std;

const string END_COLOR = "\033[0m";
const int MAX_VAL = 255;
/*
old code: 
#include <iostream>
using namespace std;

int main() {
    cout << "\033[1;41mbold red text\033[0m\n";
    return 0;

NOTE: \033[1;41 is the color start, \033[0m is the color end

*/

// ref: https://en.wikipedia.org/wiki/ANSI_escape_code#24-bit

// ESC[ 38;2;⟨r⟩;⟨g⟩;⟨b⟩ m Select RGB foreground color
// ESC[ 48;2;⟨r⟩;⟨g⟩;⟨b⟩ m Select RGB background color

class colorPrint {
    public:
    int r = 0;
    int g = 0;
    int b = 0;
    colorPrint(int r, int g, int b) {
        if (r < 0 || r > MAX_VAL) {
            throw "r must be between 0 and " + std::to_string(MAX_VAL);
        }
        if (g < 0 || g > MAX_VAL) {
            throw "g must be between 0 and 7" + std::to_string(MAX_VAL);
        }
        if (b < 0 || b > MAX_VAL) {
            throw "b must be between 0 and 7" + std::to_string(MAX_VAL);
        }
        this->r = r;
        this->g = g;
        this->b = b;
    }
    string to_string() {
        return "\033[48;2;"+std::to_string(r)+";"+std::to_string(g)+";"+std::to_string(b)+"m";
    }
    friend ostream& operator<<(ostream& os, colorPrint& c) {
        os << c.to_string();
        return os;
    }
};

class pixel : public colorPrint {
    public:
    string c = "  ";
    pixel(int r, int g, int b) : colorPrint(r, g, b) {};
    friend ostream& operator<<(ostream& os, pixel& p) {
        os << p.to_string() << p.c << END_COLOR;
        return os;
    }

};