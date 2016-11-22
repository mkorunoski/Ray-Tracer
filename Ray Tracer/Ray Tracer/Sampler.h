#ifndef SAMPLER_H
#define SAMPLER_H

#include <glm\glm.hpp>

#include "Sample.h"

class Sampler
{	
public:
	Sampler() {}
	Sampler(int width, int height);
	Sampler& operator=(const Sampler& sampler);

	bool generateSample(Sample* sample);
private:
	int width;
	int height;
	Sample currSample;
};

#endif

