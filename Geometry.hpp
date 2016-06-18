#pragma once

#include "Ray.hpp"
#include "Intersection.hpp"

struct Geometry {
	virtual Intersection intersect(const Ray& ray) const = 0;
};