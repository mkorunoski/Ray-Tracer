#include "Vertex.h"

Vertex::Vertex(const Point& position, const Normal& normal)
{
	this->position = position;
	this->normal = normal;
}

Vertex& Vertex::operator=(const Vertex& vertex)
{
	position = vertex.position;
	return *this;
}