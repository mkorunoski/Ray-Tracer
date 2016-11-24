#ifndef VECTOR_H
#define VECTOR_H

#include <glm\glm.hpp>
#include "Point.h"

class Vector
{
public:
	Vector() { }
	Vector(float x, float y, float z);
	Vector& operator=(const Vector& vector);

	friend Vector operator+(const Vector& v1, const Vector& v2);
	friend Vector operator-(const Vector& v1, const Vector& v2);
	friend Vector operator*(float s, const Vector& v);
	friend Vector operator/(float s, const Vector& v);

	Vector& normalize();
	Vector cross(const Vector& v);
	static Vector fromPoints(const Point& start, const Point& end);

	~Vector() { }
private:
	glm::vec3 direction;
};

#endif

