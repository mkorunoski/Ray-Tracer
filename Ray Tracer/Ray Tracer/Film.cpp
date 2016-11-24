#include "Film.h"

Film::Film()
{
	width = 0;
	height = 0;
}

Film::Film(int width, int height)
{
	FreeImage_Initialise();
	this->width = width;
	this->height = height;
	const int size = 3 * width * height;
	pixels = new BYTE[size];
	for (int i = 0; i < size; ++i)
		pixels[i] = 0;	
}

Film& Film::operator=(const Film& film)
{
	if (width != 0 && height != 0)
		delete[] pixels;
	width = film.width;
	height = film.height;
	const int size = 3 * width * height;
	pixels = new BYTE[size];
	for (int i = 0; i < size; ++i)
		pixels[i] = film.pixels[i];
	return *this;
}

void Film::writeImage(const std::string& fname)
{	
	FIBITMAP *img = FreeImage_ConvertFromRawBits(pixels, width, height, 3 * width, 24, 0xFF0000, 0x00FF00, 0x0000FF, false);	
	FreeImage_Save(FIF_PNG, img, fname.c_str(), 0);	
}

void Film::commit(const Sample& sample, const Color& color)
{
	int pos = 3 * (int)sample.getI() * width + 3 * (int)sample.getJ();
	pixels[pos + 0] = color.getB();
	pixels[pos + 1] = color.getG();
	pixels[pos + 2] = color.getR();
}

Film::~Film()
{	
	delete[] pixels;
	FreeImage_DeInitialise();
}
