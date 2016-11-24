#include "Ray.h"

Ray::Ray(const Point& point, const Vector& vector)
{
	this->point = point;
	this->vector = vector;
}