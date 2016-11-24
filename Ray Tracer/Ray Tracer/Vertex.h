#ifndef VERTEX_H
#define VERTEX_H

#include "Point.h"
#include "Normal.h"

class Vertex
{
public:
	Vertex() { }
	Vertex(const Point& position, const Normal& normal);
	Vertex& operator=(const Vertex& vertex);

	~Vertex() { }
private:
	Point position;
	Normal normal;
};

#endif