#include "Sample.h"

Sample::Sample()
{
	position = glm::vec2(0.5f, 0.5f);
}

Sample::Sample(float x, float y)
{
	position = glm::vec2(x, y);
}

Sample& Sample::operator=(const Sample& sample)
{
	position = sample.position;
	return *this;
}