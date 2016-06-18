#pragma once

#include <vector>
#include <memory>
#include "Geometry.hpp"
#include "PointLight.hpp"

class Scene {
public:
	std::vector<std::shared_ptr<Geometry>> renderables;
	std::vector<std::shared_ptr<PointLight>> lights;
};