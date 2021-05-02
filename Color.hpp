#pragma once

#include <string>

namespace pandemic{
    enum class Color {
        Blue,
        Yellow,
        Black,
        Red
    };
    std::string color_to_string(Color c);
}