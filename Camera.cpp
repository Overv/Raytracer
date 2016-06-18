#include "Camera.hpp"

#define GLM_FORCE_RADIANS
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(float fovy, float aspectRatio) {
	invProjection = glm::inverse(glm::infinitePerspective(fovy, aspectRatio, 1.0f));
}

glm::vec3 Camera::unproject(const glm::vec2& deviceCoords) const {
	return glm::vec3(glm::normalize(invProjection * glm::vec4(deviceCoords, 1.0f, 1.0f)));
}

Ray Camera::getRay(const glm::vec2& deviceCoords) const {
	return Ray(glm::vec3(), unproject(deviceCoords));
}