#include <iostream>
#include <SDL.h>

using namespace std;


int main(int argc, char* args[]) {
	
	// Setting Window Width and Height.
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;

	// Failure message
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL_INIT failed." << endl;
		return 1;
	}

	//Window creation -- size is carried from previously deifined Width and Height variables above.
	SDL_Window* window = SDL_CreateWindow("Particle Fire Explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (window == NULL) {
		SDL_Quit;
		return 2;
	}

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

	// renderer failure
	if (renderer == NULL) {
		cout << "Could not create renderer!" << endl;
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 3;
	}

	// texture failure
	if (texture == NULL) {
		cout << "Could not create texture!" << endl;
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 4;
	}

	Uint32* buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

	memset(buffer, 0xFF, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

	SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH*sizeof(Uint32));
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);

	bool quit = false;
	SDL_Event event;

	while (!quit) {


		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}
		}
	}
	
	delete[] buffer;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(texture);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
