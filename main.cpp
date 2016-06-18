#include <iostream>
#include <SDL.h>
#include <glm/glm.hpp>

#include "Config.hpp"
#include "Raytracer.hpp"
#include "Camera.hpp"
#include "Sphere.hpp"
#include "Disk.hpp"

// TODO:
//
// - Visibility testing for lights (light.getLightEnergy(point))
// - Area lights
// - Add Colorf class for high accuracy colors

int main(int argc, char* argv[]) {
	// Set up raytracer
	Camera camera(glm::radians(90.0f), Config::WIDTH / (float) Config::HEIGHT);

	Scene scene;

	auto baseMaterial = std::make_shared<PhongMaterial>(Color(16, 0, 0), Color(255, 0, 0), Color(255, 255, 255), 20.0f);

	scene.renderables.push_back(std::make_shared<Sphere>(glm::vec3(0.0f, 0.0f, -4.0f), 1.0f, baseMaterial));
	scene.renderables.push_back(std::make_shared<Disk>(glm::vec3(0.0f, -1.0f, -4.0f), glm::vec3(0.0f, 1.0f, 0.0f), 2.0f, baseMaterial));

	scene.lights.push_back(std::make_shared<PointLight>(glm::vec3(0.0f, 10.0f, -2.0f)));

	Raytracer raytracer(Config::WIDTH, Config::HEIGHT, camera, scene);

	// Set up SDL
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window* window = SDL_CreateWindow("Raytracer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, raytracer.getWidth(), raytracer.getHeight(), 0);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

	SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, raytracer.getWidth(), raytracer.getHeight());

	// Main loop
	bool running = true;
	while (running) {
		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				running = false;
			}
		}

		auto pixels = raytracer.render_frame();
		SDL_UpdateTexture(texture, nullptr, pixels.data(), raytracer.getWidth() * sizeof(uint32_t));

		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texture, nullptr, nullptr);
		SDL_RenderPresent(renderer);
	}

	SDL_Quit();

	return 0;
}