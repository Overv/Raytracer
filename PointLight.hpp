#pragma once

#include <glm/vec3.hpp>
#include "Color.hpp"
#include "Scene.hpp"

struct PointLight {
	PointLight(const glm::vec3& pos, const Color& color = Color(255, 255, 255)) : pos(pos), color(color) {}

	Color getLightEnergy(const Scene& scene, const glm::vec3& pos) const;

	glm::vec3 pos;
	Color color;
};