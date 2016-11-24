#ifndef SHAPE_H
#define SHAPE_H

#include "Ray.h"
#include "LocalGeo.h"

class Shape
{
public:
	virtual bool intersect(const Ray& ray, float thit, LocalGeo& local) = 0;
	virtual bool intersectP(const Ray& ray) = 0;
};

#endif

