#include <iostream>
#include <FreeImage.h>

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Utils.h"
#include "Film.h"
#include "Camera.h"
#include "Sampler.h"
#include "Sample.h"
#include "Vertex.h"
#include "Point.h"

int main(char ** argv, int argc)
{
	std::string imageOutputName = "slika.png";
	std::string fname = "scene1.test";

	Film film;
	Sampler sampler;
	Camera camera;

	// triangles
	std::vector<Vertex> vertices;
	// spheres
	std::vector<Point> positions;

	// Parsing
	std::ifstream ifs(fname);
	std::string line;
	std::string prefix;
	std::vector<std::string> tokens;
	while (std::getline(ifs, line))
	{
		prefix = "size";		
		if (line.substr(0, prefix.size()) == prefix) {	
			tokens = std::vector<std::string>();
			Utils::split(line, ' ', tokens);
			int w = std::stoi(tokens.at(1));
			int h = std::stoi(tokens.at(2));
			film = Film(w, h);
			sampler = Sampler(film);			
		}

		prefix = "camera";
		if (line.substr(0, prefix.size()) == prefix) {
			tokens = std::vector<std::string>();
			Utils::split(line, ' ', tokens);
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

		prefix = "maxverts";
		if (line.substr(0, prefix.size()) == prefix) {
			tokens = std::vector<std::string>();
			Utils::split(line, ' ', tokens);
			int maxverts = std::stoi(tokens.at(1));
			vertices = std::vector<Vertex>(maxverts);

			std::getline(ifs, line);

			prefix = "vertex";			
			for (int i = 0; i < maxverts; ++i)
			{		
				std::getline(ifs, line);
				tokens = std::vector<std::string>();
				Utils::split(line, ' ', tokens);
				float x = std::stof(tokens.at(1));
				float y = std::stof(tokens.at(2));
				float z = std::stof(tokens.at(3));
				Point point(x, y, z);
				Normal normal(0, 0, 0);
				Vertex vertex(point, normal);
				vertices.push_back(vertex);
			}
		}
	}

	// Start
	Sample sample;
	Ray ray;
	while (sampler.generateSample(sample))
	{		
		camera.generateRay(sample, ray, film);
		film.commit(sample, Color(255, 0, 0));
	}
	film.writeImage(imageOutputName);

	return 0;
}