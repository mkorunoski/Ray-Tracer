#include "Normal.h"

Normal::Normal(float x, float y, float z)
{
	direction = glm::vec3(x, y, z);
}

Normal& Normal::operator=(const Normal& normal)
{
	direction = normal.direction;
	return *this;
}

Normal operator+(const Normal& n1, const Normal& n2)
{
	glm::vec3 direction = glm::normalize(n1.direction + n2.direction);
	return Normal(direction.x, direction.y, direction.z);
}

Normal operator-(const Normal& n1, const Normal& n2)
{
	glm::vec3 direction = glm::normalize(n1.direction - n2.direction);
	return Normal(direction.x, direction.y, direction.z);
}