#include "Sphere.h"

Sphere::Sphere(Point* poistion, float radius)
{
	this->position = position;
	this->radius = radius;
}

Sphere& Sphere::operator=(const Sphere& sphere)
{
	position = sphere.position;
	radius = sphere.radius;
	return *this;
}

bool Sphere::intersect(const Ray& ray, float thit, LocalGeo& local)
{

	return true;
}

bool Sphere::intersectP(const Ray& ray)
{

	return true;
}