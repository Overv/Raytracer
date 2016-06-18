#pragma once

#include <memory>
#include <glm/vec3.hpp>
#include "Color.hpp"

struct PhongMaterial;

struct Intersection {
	Intersection(const Ray& ray) : hit(false), ray(ray), distance(0.0f) {};

	Intersection(const Ray& ray, const glm::vec3& pos, const glm::vec3& normal, std::shared_ptr<PhongMaterial> material)
		: hit(true), ray(ray), pos(pos), normal(normal), material(material), distance(glm::distance(ray.origin, pos)) {}

	bool hit;

	Ray ray;
	float distance;
	glm::vec3 pos;
	glm::vec3 normal;
	std::shared_ptr<PhongMaterial> material;
};