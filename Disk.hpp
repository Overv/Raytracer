#pragma once

#include "Geometry.hpp"
#include "Ray.hpp"
#include "Intersection.hpp"
#include "PhongMaterial.hpp"

struct Disk : Geometry {
	Disk(const glm::vec3& center, const glm::vec3& normal, float radius, std::shared_ptr<PhongMaterial> material)
		: center(center), normal(normal), radius(radius), material(material) {}

	Intersection intersect(const Ray& ray) const;

	glm::vec3 center;
	glm::vec3 normal;
	float radius;
	std::shared_ptr<PhongMaterial> material;
};