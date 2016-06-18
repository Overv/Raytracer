#pragma once

#include <glm/vec3.hpp>
#include "Ray.hpp"
#include "Intersection.hpp"
#include "PhongMaterial.hpp"

struct Sphere {
	Sphere(const glm::vec3& center, float radius, std::shared_ptr<PhongMaterial> material)
		: center(center), radius(radius), material(material) {};

	Intersection intersect(const Ray& ray) const;

	glm::vec3 center;
	float radius;
	std::shared_ptr<PhongMaterial> material;
};