#include <iostream>
#include <FreeImage.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "Film.h"
#include "Camera.h"
#include "Sampler.h"
#include "Sample.h"

void split(const std::string &s, char delim, std::vector<std::string> &elems) {
	std::stringstream ss;
	ss.str(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
}

int main(char ** argv, int argc)
{
	std::string imageOutputName = "slika.png";
	std::string fname = "scene1.test";

	Film film;
	Sampler sampler;
	Camera camera;

	// Parsing
	std::ifstream ifs(fname);
	std::string line;
	std::string prefix;
	while (std::getline(ifs, line))
	{
		prefix = "size";		
		if (line.substr(0, prefix.size()) == prefix) {			
			std::vector<std::string> tokens;
			split(line, ' ', tokens);
			int w = std::stoi(tokens.at(1));
			int h = std::stoi(tokens.at(2));
			film = Film(w, h);
			sampler = Sampler(w, h);			
		}

		prefix = "camera";
		if (line.substr(0, prefix.size()) == prefix) {
			std::vector<std::string> tokens;
			split(line, ' ', tokens);
			float lookFromX = std::stof(tokens.at(1));
			float lookFromY = std::stof(tokens.at(2));
			float lookFromZ = std::stof(tokens.at(3));
			float lookAtX = std::stof(tokens.at(4));
			float lookAtY = std::stof(tokens.at(5));
			float lookAtZ = std::stof(tokens.at(6));
			float upX = std::stof(tokens.at(7));
			float upY = std::stof(tokens.at(8));
			float upZ = std::stof(tokens.at(9));
			int fov = std::stoi(tokens.at(10));

			camera = Camera(lookFromX, lookFromY, lookFromZ,
				lookAtX, lookAtY, lookAtZ,
				upX, upY, upZ,
				fov);
		}
	}

	// Start
	Sample sample;
	while (sampler.generateSample(&sample))
	{
		film.commit(sample, Color(255, 255, 0));
	}
	film.writeImage(imageOutputName);

	return 0;
}