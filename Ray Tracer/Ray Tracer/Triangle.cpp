#include "Triangle.h"

Triangle::Triangle(Vertex* vertex1, Vertex* vertex2, Vertex* vertex3)
{
	this->vertex1 = vertex1;
	this->vertex2 = vertex2;
	this->vertex3 = vertex3;	
}

bool Triangle::intersect(const Ray& ray, float thit, LocalGeo& local)
{

	return true;	
}

bool Triangle::intersectP(const Ray& ray)
{

	return true;
}