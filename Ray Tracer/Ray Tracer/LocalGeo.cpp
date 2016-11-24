#include "LocalGeo.h"

LocalGeo::LocalGeo(const Point& position, const Normal& normal)
{
	this->position = position;
	this->normal = normal;
}

LocalGeo& LocalGeo::operator=(const LocalGeo& localGeo)
{
	position = localGeo.position;
	normal = localGeo.normal;
	return *this;
}