#include "Disk.hpp"
#include <glm/gtx/norm.hpp>

Intersection Disk::intersect(const Ray& ray) const {
	float denom = glm::dot(normal, ray.dir);

	if (std::abs(denom) < 1e-6) {
		return Intersection(ray);
	}
	
	glm::vec3 p0l0 = center - ray.origin;
	float t = glm::dot(p0l0, normal) / denom;
	glm::vec3 pos = ray.origin + t * ray.dir;

	if (t < 0.0f || glm::distance2(pos, center) > radius * radius) {
		return Intersection(ray);
	}

	return Intersection(
		ray,
		pos,
		normal,
		material
	);
}