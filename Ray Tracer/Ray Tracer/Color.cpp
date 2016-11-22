#include "Color.h"

Color::Color()
{
}

Color::Color(BYTE r, BYTE g, BYTE b)
{
	rgb = glm::uvec3(r, g, b);
}

Color& Color::operator = (const Color& color)
{
	rgb = color.rgb;
	return *this;
}

Color::~Color()
{
}
