#include "Point.h"

Point::Point(float x, float y, float z)
{
	coordinates = glm::vec3(x, y, z);
}

Point& Point::operator=(const Point& p)
{
	coordinates = p.coordinates;
	return *this;
}

Point operator+(const Point& p1, const Point& p2)
{
	glm::vec3 position = p1.coordinates + p2.coordinates;
	return Point(position.x, position.y, position.z);
}

Point operator-(const Point& p1, const Point& p2)
{
	glm::vec3 position = p1.coordinates - p2.coordinates;
	return Point(position.x, position.y, position.z);
}
