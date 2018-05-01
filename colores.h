#pragma once
#include <tuple>
#include <iostream>
enum class primaryColors : unsigned char
{
	RED = 0, GREEN = 1, BLUE = 2
};
//a las tuplas se accede mediante std::get<enumVal>(tupleVar) , Ej : colorGBR colorAzul(0,255,0);
															//        std::get<RED>(colorAzul) == 0 -> verdadero

using hue = std::uint16_t;
using sat = std::uint16_t;
using val = std::uint16_t;
using colorHSV = std::tuple<hue,sat,val>;
const colorHSV c_nullColorHSV = colorHSV(0, 0, 0);

using colorBGR = std::tuple<unsigned char, unsigned char, unsigned char>;
const colorBGR c_nullColorBGR(0, 0, 0);
