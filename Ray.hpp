#pragma once

#include <glm/vec3.hpp>

class Ray {
public:
	Ray(const glm::vec3& origin, const glm::vec3& dir) : origin(origin), dir(dir) {}

	glm::vec3 origin, dir;
};