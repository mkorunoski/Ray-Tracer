#ifndef NORMAL_H
#define NORMAL_H

#include <glm\glm.hpp>

class Normal
{
public:
	Normal() { }
	Normal(float x, float y, float z);
	Normal& operator=(const Normal& normal);

	friend Normal operator+(const Normal& n1, const Normal& n2);
	friend Normal operator-(const Normal& n1, const Normal& n2);

	~Normal() { }
private:
	glm::vec3 direction;
};

#endif
