#include "Sample.h"

Sample::Sample()
{
	position = glm::vec2(0.5f, 0.5f);
}

Sample::Sample(float i, float j)
{
	position = glm::vec2(i, j);
}

Sample& Sample::operator=(const Sample& sample)
{
	position = sample.position;
	return *this;
}