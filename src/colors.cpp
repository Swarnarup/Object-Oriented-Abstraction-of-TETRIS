#include "colors.h"

const Color bg = {0, 51, 102, 255};
const Color green = {0, 255, 0, 255};
const Color darkBlue = {0, 0, 102, 255};
const Color red = {255, 0, 0, 255};
const Color darkRed = {102, 0, 0, 255};
const Color lightRed = {255, 51, 51, 255};
const Color yellow = {255, 255, 0, 255};
const Color cyan = {0, 255, 255, 255};

std::vector<Color> GetColors()
{
    return {bg, green, darkBlue, red, darkRed, lightRed, yellow, cyan};
}