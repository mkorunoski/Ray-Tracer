#ifndef SAMPLE_H
#define SAMPLE_H

#include <glm\glm.hpp>

class Sample
{
	friend class Sampler;

public:
	Sample();
	Sample(float x, float y);
	Sample& operator=(const Sample& sample);

	inline float getX() const { return position.x; }
	inline float getY() const { return position.y; }

	~Sample() { }
private:
	glm::vec2 position;
};

#endif

