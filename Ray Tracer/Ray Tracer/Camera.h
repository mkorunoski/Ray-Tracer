#ifndef CAMERA_H
#define CAMERA_H

#include <glm\glm.hpp>

#include "Sample.h"
#include "Ray.h"
#include "Film.h"

class Camera
{
public:
	Camera() { }
	Camera(float lookFromX, float lookFromY, float lookFromZ,
		float lookAtX, float lookAtY, float lookAtZ,
		float upX, float upY, float upZ,
		int fov);
	Camera& operator=(const Camera& camera);

	void generateRay(Sample& sample, Ray& ray, const Film& film);

	~Camera() { }
private:
	Point lookFrom;
	Point lookAt;
	Vector up;
	int fovy;
};

#endif

