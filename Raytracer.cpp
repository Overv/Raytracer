#include "Raytracer.hpp"
#include <algorithm>

const std::vector<Color>& Raytracer::render_frame() {
	clear(Color(0, 0, 0));
	
	for (uint32_t x = 0; x < width; x++) {
		for (uint32_t y = 0; y < height; y++) {
			glm::vec2 deviceCoords = getDeviceCoords(x, y);
			Ray ray = camera.getRay(deviceCoords);

			Intersection closestIntersection(ray);
			
			for (const auto& renderable : scene.renderables) {
				Intersection intersection = renderable->intersect(ray);

				if (!closestIntersection.hit || intersection.distance < closestIntersection.distance) {
					closestIntersection = intersection;
				}
			}

			if (closestIntersection.hit) {
				Color totalLight;

				for (const auto& light : scene.lights) {
					totalLight = totalLight + closestIntersection.material->calculateColor(closestIntersection, *light);
				}

				setPixel(x, y, totalLight);
			}
		}
	}

	return pixels;
}

uint32_t Raytracer::getWidth() const {
	return width;
}

uint32_t Raytracer::getHeight() const {
	return height;
}

void Raytracer::clear(const Color& color) {
	std::fill(pixels.begin(), pixels.end(), color);
}

void Raytracer::setPixel(uint32_t x, uint32_t y, const Color& color) {
	pixels[y * width + x] = color;
}

glm::vec2 Raytracer::getDeviceCoords(uint32_t x, uint32_t y) {
	return glm::vec2(
		(x / (float) width) * 2.0f - 1.0f,
		-((y / (float) height) * 2.0f - 1.0f)
	);
}