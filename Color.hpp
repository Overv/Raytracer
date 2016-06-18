#pragma once

#include <cstdint>
#include <cmath>
#include <algorithm>
#include <glm/glm.hpp>
#include <glm/vec3.hpp>

struct Color {
	uint32_t color;

	Color(uint8_t r = 0x00, uint8_t g = 0x00, uint8_t b = 0x00, uint8_t a = 0xFF) {
		color = (a << 24) | (r << 16) | (g << 8) | b;
	}

	Color(const glm::vec4& vec)
		: Color((uint8_t) std::min(255.0f, (vec.r * 255.0f)), (uint8_t) std::min(255.0f, (vec.g * 255.0f)), (uint8_t) std::min(255.0f, (vec.b * 255.0f)), (uint8_t) std::min(255.0f, (vec.a * 255.0f))) {}

	Color operator*(const Color& other) const {
		glm::vec4 a = getVector();
		glm::vec4 b = other.getVector();

		return getVector() * other.getVector();
	}

	Color operator+(const Color& other) const {
		return Color(getVector() + other.getVector());
	}

	Color operator*(float c) const {
		return getVector() * c;
	}

	glm::vec4 getVector() const {
		return glm::vec4(getR(), getG(), getB(), getA()) / 255.0f;
	}

	uint8_t getA() const { return (color >> 24) & 0xFF; }
	uint8_t getR() const { return (color >> 16) & 0xFF; }
	uint8_t getG() const { return (color >> 8) & 0xFF; }
	uint8_t getB() const { return (color >> 0) & 0xFF; }

	static Color fromNormal(const glm::vec3& normal) {
		uint8_t r = (uint8_t) ((normal.x / 2.0f + 0.5f) * 255.0f);
		uint8_t g = (uint8_t) ((normal.y / 2.0f + 0.5f) * 255.0f);
		uint8_t b = (uint8_t) ((normal.z / 2.0f + 0.5f) * 255.0f);

		return Color(r, g, b);
	}

	static Color fromNormalAbs(const glm::vec3& normal) {
		uint8_t r = (uint8_t) (std::abs(normal.x) * 255.0f);
		uint8_t g = (uint8_t) (std::abs(normal.y) * 255.0f);
		uint8_t b = (uint8_t) (std::abs(normal.z) * 255.0f);

		return Color(r, g, b);
	}
};