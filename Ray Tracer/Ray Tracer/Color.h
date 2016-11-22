#include <glm\glm.hpp>
#include <FreeImage.h>

class Color
{
public:
	Color();
	Color(BYTE r, BYTE g, BYTE b);
	Color& operator=(const Color& color);

	inline BYTE getR() const { return rgb.r; }
	inline BYTE getG() const { return rgb.g; }
	inline BYTE getB() const { return rgb.b; }

	~Color();
private:
	glm::uvec3 rgb;
};

