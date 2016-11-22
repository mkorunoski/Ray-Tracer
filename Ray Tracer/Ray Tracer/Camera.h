#include <glm\glm.hpp>

class Camera
{
public:
	Camera() { }
	Camera(float lookFromX, float lookFromY, float lookFromZ,
		float lookAtX, float lookAtY, float lookAtZ,
		float upX, float upY, float upZ,
		int fov);
	Camera& operator=(const Camera& camera);

	~Camera() { }
private:
	glm::vec3 lookFrom;
	glm::vec3 lookAt;
	glm::vec3 up;
	int fov;
};

