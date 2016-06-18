#pragma once

#include <cstdint>
#include <vector>
#include <glm/vec2.hpp>

#include "Color.hpp"
#include "Camera.hpp"
#include "Scene.hpp"

class Raytracer {
public:
	Raytracer(uint32_t width, uint32_t height, Camera& camera, Scene& scene)
		: width(width), height(height), camera(camera), scene(scene) {

		this->pixels.resize(width * height);
	}

	const std::vector<Color>& render_frame();

	uint32_t getWidth() const;
	uint32_t getHeight() const;

private:
	std::vector<Color> pixels;
	uint32_t width, height;

	Camera& camera;
	Scene& scene;

	void clear(const Color& color);
	void setPixel(uint32_t x, uint32_t y, const Color& color);

	glm::vec2 getDeviceCoords(uint32_t x, uint32_t y);
};