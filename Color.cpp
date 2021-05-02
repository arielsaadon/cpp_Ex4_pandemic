#include "Color.hpp"
#include <string>

using namespace std;
using namespace pandemic;

string pandemic::color_to_string(Color c){
    switch (c) {
        case Color::Blue:
            return "Blue";
        case Color::Yellow:
            return "Yellow";
        case Color::Black:
            return "Black";
        case Color::Red:
            return "Red";
    }
    return "";
}