#pragma once

#include "Color.hpp"
#include "Intersection.hpp"
#include "PointLight.hpp"
#include <algorithm>

struct PhongMaterial {
	PhongMaterial(const Color& ambient = Color(), const Color& diffuse = Color(), const Color& specular = Color(), float shininess = 1.0f)
		: ambient(ambient), diffuse(diffuse), specular(specular), shininess(shininess) {}

	Color calculateColor(const Scene& scene, const Intersection& intersection, const PointLight& light) const {
		Color energy = light.getLightEnergy(scene, intersection.pos + intersection.normal * 1e-5f);

		float diffuseFactor = std::max(0.0f, glm::dot(intersection.normal, glm::normalize(light.pos - intersection.pos)));

		glm::vec3 reflection = glm::reflect(glm::normalize(light.pos - intersection.pos), intersection.normal);
		float specularFactor = std::pow(std::max(0.0f, glm::dot(glm::normalize(intersection.pos - intersection.ray.origin), reflection)), shininess);

		return diffuse * energy * diffuseFactor + specular * energy * specularFactor + ambient;
	}

	Color ambient;
	Color diffuse;
	Color specular;
	float shininess;
};