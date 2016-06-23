#pragma once

#include <vector>
#include <memory>

struct Geometry;
struct PointLight;

class Scene {
public:
	std::vector<std::shared_ptr<Geometry>> geometry;
	std::vector<std::shared_ptr<PointLight>> lights;
};