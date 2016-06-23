#include "PointLight.hpp"
#include "Scene.hpp"
#include "Ray.hpp"
#include "Intersection.hpp"
#include "Geometry.hpp"

Color PointLight::getLightEnergy(const Scene& scene, const glm::vec3& pos) const {
	Ray ray(pos, glm::normalize(this->pos - pos));

	// TODO: Test if intersection is actually between position and light
	for (const auto& geom : scene.geometry) {
		Intersection intersection = geom->intersect(ray);

		if (intersection.hit) {
			return Color(0, 0, 0);
		}
	}

	return color;
}