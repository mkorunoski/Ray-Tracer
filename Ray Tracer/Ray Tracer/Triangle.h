#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <vector>
#include "Shape.h"
#include "Vertex.h"
#include "Ray.h"
#include "LocalGeo.h"

class Triangle : public Shape
{
public:
	Triangle() { }
	Triangle(Vertex* vertex1, Vertex* vertex2, Vertex* vertex3);

	bool intersect(const Ray& ray, float thit, LocalGeo& local);
	bool intersectP(const Ray& ray);

	~Triangle() { }
private:
	Vertex* vertex1;
	Vertex* vertex2;
	Vertex* vertex3;
};

#endif