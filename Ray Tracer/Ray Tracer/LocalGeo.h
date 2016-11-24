#ifndef LOCALGEO_H
#define LOCALGEO_H

#include "Point.h"
#include "Normal.h"

class LocalGeo
{
public:
	LocalGeo() { }
	LocalGeo(const Point& position, const Normal& normal);
	LocalGeo& operator=(const LocalGeo& localGeo);

	~LocalGeo() { }
private:
	Point position;
	Normal normal;
};

#endif