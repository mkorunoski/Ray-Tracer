#ifndef Sphere_H
#define Sphere_H

#include "Shape.h"
#include "Point.h"
#include "Ray.h"
#include "LocalGeo.h"

class Sphere : public Shape
{
public:
	Sphere() { }
	Sphere(Point* poistion, float radius);
	Sphere& operator=(const Sphere& sphere);

	bool intersect(const Ray& ray, float thit, LocalGeo& local);
	bool intersectP(const Ray& ray);

	~Sphere() { }
private:
	Point* position;
	float radius;
};

#endif