#include "Sphere.hpp"
#include <glm/glm.hpp>
#include <algorithm>

Intersection Sphere::intersect(const Ray& ray) const {
	float t0, t1;

	glm::vec3 L = center - ray.origin;
	float tca = glm::dot(center, ray.dir);
	float d2 = glm::dot(L, L) - tca * tca;
	if (d2 > radius) return Intersection(ray);
	float thc = sqrt(radius - d2);
	t0 = tca - thc;
	t1 = tca + thc;

	if (t0 > t1) std::swap(t0, t1);

	if (t0 < 0) {
		t0 = t1;
		if (t0 < 0) return Intersection(ray);
	}

	float t = t0;
	glm::vec3 pos = ray.origin + ray.dir * t;

	return Intersection(
		ray,
		pos,
		glm::normalize(pos - center),
		material
	);
}