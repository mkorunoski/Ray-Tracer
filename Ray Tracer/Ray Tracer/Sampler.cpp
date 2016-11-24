#include "Sampler.h"

Sampler::Sampler(Film& film)
{
	this->film = &film;
	currSample = Sample();
}

Sampler& Sampler::operator=(const Sampler& sampler)
{
	film = sampler.film;
	currSample = sampler.currSample;
	return *this;
}

bool Sampler::generateSample(Sample& sample)
{
	sample = currSample;

	currSample.setJ(currSample.getJ() + 1.0f);	
	if (currSample.getJ() > film->getWidth())
	{
		currSample.setJ(0.0f);
		currSample.setI(currSample.getI() + 1.0f);		
	}
	if (currSample.getI() > film->getHeight())
		return false;

	return true;
}