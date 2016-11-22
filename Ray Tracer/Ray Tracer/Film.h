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

	void writeImage(const std::string& fname);
	void commit(const Sample& sample, const Color& color);

	~Film();
private:
	int width;
	int height;
	BYTE* pixels;
};

