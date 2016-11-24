#ifndef SAMPLE_H
#define SAMPLE_H

#include <glm\glm.hpp>

class Sample
{
public:
	Sample();
	Sample(float i, float j);
	Sample& operator=(const Sample& sample);

	inline float getI() const { return position.x; }
	inline float getJ() const { return position.y; }
	inline void setI(float i) { position.x += i; }
	inline void setJ(float j) { position.y += j; }

	~Sample() { }
private:
	glm::vec2 position;
};

#endif

