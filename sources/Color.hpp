#pragma once

#include <string>

namespace pandemic{
    enum class Color {
        Blue,
        Yellow,
        Black,
        Red
    };
    inline std::string color_to_string(Color c){
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
}