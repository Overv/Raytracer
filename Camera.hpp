#pragma once

#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include "Ray.hpp"

class Camera {
public:
	Camera(float fovy, float aspectRatio);

	glm::vec3 unproject(const glm::vec2& deviceCoords) const;
	Ray getRay(const glm::vec2& deviceCoords) const;

private:
	glm::mat4 invProjection;
};