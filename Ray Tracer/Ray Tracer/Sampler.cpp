#include "Sampler.h"

Sampler::Sampler(int width, int height)
{
	this->width = width;
	this->height = height;
	currSample = Sample();
}

Sampler& Sampler::operator=(const Sampler& sampler)
{
	width = sampler.width;
	height = sampler.height;
	currSample = sampler.currSample;
	return *this;
}

bool Sampler::generateSample(Sample* sample)
{
	*sample = currSample;

	currSample.position.y += 1.0f;
	if (currSample.position.y > width)
	{
		currSample.position.y = 0.0f;
		currSample.position.x += 1.0f;
	}
	if (currSample.position.x > height)
		return false;

	return true;
}