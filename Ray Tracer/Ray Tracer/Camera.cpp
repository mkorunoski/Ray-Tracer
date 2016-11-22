#include "Camera.h"

Camera::Camera(float lookFromX, float lookFromY, float lookFromZ,
	float lookAtX, float lookAtY, float lookAtZ,
	float upX, float upY, float upZ,
	int fov)
{
	this->lookFrom = glm::vec3(lookFromX, lookFromY, lookFromZ);
	this->lookAt = glm::vec3(lookAtX, lookAtY, lookAtZ);
	this->up = glm::vec3(upX, upY, upZ);
	this->fov = fov;
}

Camera& Camera::operator=(const Camera& camera)
{
	lookFrom = camera.lookFrom;
	lookAt = camera.lookAt;
	up = camera.up;
	fov = camera.fov;
	return *this;
}