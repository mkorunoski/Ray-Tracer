#ifndef SAMPLER_H
#define SAMPLER_H

#include <glm\glm.hpp>

#include "Sample.h"
#include "Film.h"

class Sampler
{	
public:
	Sampler() {}
	Sampler(Film& film);
	Sampler& operator=(const Sampler& sampler);

	bool generateSample(Sample& sample);
private:
	Film* film;
	Sample currSample;
};

#endif

