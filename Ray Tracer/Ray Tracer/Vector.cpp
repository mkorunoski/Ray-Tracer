#include "Vector.h"

Vector::Vector(float x, float y, float z)
{
	direction = glm::vec3(x, y, z);
}

Vector& Vector::operator=(const Vector& vector)
{
	direction = vector.direction;
	return *this;
}

Vector operator+(const Vector& v1, const Vector& v2)
{
	glm::vec3 direction = v1.direction + v2.direction;
	return Vector(direction.x, direction.y, direction.z);
}

Vector operator-(const Vector& v1, const Vector& v2)
{
	glm::vec3 direction = v1.direction - v2.direction;
	return Vector(direction.x, direction.y, direction.z);
}

Vector operator*(float s, const Vector& v)
{
	glm::vec3 direction = v.direction * s;
	return Vector(direction.x, direction.y, direction.z);
}

Vector operator/(float s, const Vector& v)
{
	glm::vec3 direction = v.direction / s;
	return Vector(direction.x, direction.y, direction.z);
}

Vector& Vector::normalize()
{
	direction = glm::normalize(direction);
	return *this;
}

Vector Vector::cross(const Vector& v)
{
	glm::vec3 orthogonal = glm::cross(direction, v.direction);
	return Vector(orthogonal.x, orthogonal.y, orthogonal.z);
}

Vector Vector::fromPoints(const Point& start, const Point& end)
{
	glm::vec3 direction = (end - start).getCoordinates();
	return Vector(direction.x, direction.y, direction.z);
}
