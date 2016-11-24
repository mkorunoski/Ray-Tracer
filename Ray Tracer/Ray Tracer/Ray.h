#ifndef RAY_H
#define RAY_H

#include "Point.h"
#include "Vector.h"

class Ray
{
public:
	Ray() { }
	Ray(const Point& point, const Vector& vector);

	~Ray() { }
private:
	Point point;
	Vector vector;
	float tMin;
	float tMax;
};

#endif
