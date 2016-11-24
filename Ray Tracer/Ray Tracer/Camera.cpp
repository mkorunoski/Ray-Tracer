#include "Camera.h"

Camera::Camera(float lookFromX, float lookFromY, float lookFromZ,
	float lookAtX, float lookAtY, float lookAtZ,
	float upX, float upY, float upZ,
	int fov)
{
	lookFrom = Point(lookFromX, lookFromY, lookFromZ);
	lookAt = Point(lookAtX, lookAtY, lookAtZ);
	up = Vector(upX, upY, upZ);
	fovy = fov;
}

Camera& Camera::operator=(const Camera& camera)
{
	lookFrom = camera.lookFrom;
	lookAt = camera.lookAt;
	up = camera.up;
	fovy = camera.fovy;
	return *this;
}

void Camera::generateRay(Sample& sample, Ray& ray, const Film& film) // mozi da ima bug
{
	Vector a = Vector::fromPoints(lookAt, lookFrom);

	Vector w = a.normalize();	
	Vector u = (up.cross(w)).normalize();
	Vector v = w.cross(u);

	float fovx = 2 * glm::atan(film.getWidth() * 0.5f);
	float hw = film.getWidth() * 0.5f;
	float hh = film.getHeight() * 0.5f;
	float alpha = glm::tan(fovx * 0.5f) * ((sample.getJ() - hw) / hw);
	float beta = glm::tan(fovy * 0.5f) * ((hh - sample.getI()) / hh);

	Vector rayv = (alpha * u + beta * v - w).normalize();
	ray = Ray(lookFrom, rayv);
}