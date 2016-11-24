#ifndef POINT_H
#define POINT_H

#include <glm\glm.hpp>

class Point
{	
public:
	Point() { }
	Point(float x, float y, float z);
	Point& operator=(const Point& p);

	friend Point operator+(const Point& p1, const Point& p2);
	friend Point operator-(const Point& p1, const Point& p2);

	glm::vec3 getCoordinates() { return coordinates; }

	~Point() { }
private:
	glm::vec3 coordinates;
};

#endif
