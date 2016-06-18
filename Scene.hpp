#pragma once

#include <vector>
#include <memory>
#include "Sphere.hpp"
#include "PointLight.hpp"

class Scene {
public:
	std::vector<std::shared_ptr<Sphere>> renderables;
	std::vector<std::shared_ptr<PointLight>> lights;
};