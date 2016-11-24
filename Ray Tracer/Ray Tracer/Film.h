#ifndef FILM_H
#define FILM_H

#include <FreeImage.h>
#include <string>

#include "Sample.h"
#include "Color.h"

class Film
{
public:	
	Film();
	Film(int width, int height);
	Film& operator=(const Film& film);

	inline int getWidth() const { return width; }
	inline int getHeight() const { return height; }

	void writeImage(const std::string& fname);
	void commit(const Sample& sample, const Color& color);

	~Film();
private:
	int width;
	int height;
	BYTE* pixels;
};

#endif
