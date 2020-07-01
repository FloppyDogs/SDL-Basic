#define SDL_MAIN_HANDLED


#include <iostream>
#include <SDL.h>
#include <math.h>
#include "Screen.h"

using namespace std;


int main() {

	Screen screen;

	if (screen.init() == false) {
		cout << "Error initializing SDL." << endl;
	}

	int max = 0; 

	while (true) {

		int elapsed = SDL_GetTicks();
		unsigned char red = (1 + sin(elapsed * 0.001)) * 128;
		unsigned char green = (1 + sin(elapsed * 0.002)) * 128;
		unsigned char blue = (1 + sin(elapsed * 0.003)) * 128;


		for (int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
			for (int x = 0; x < Screen::SCREEN_WIDTH; x++) {
				screen.set_pixel(x, y, red, green, blue);
			}
		}

		screen.update();

		if (screen.processEvents() == false) {
			break;
		}

		
		
	}
	
	cout << "Max:" << max << endl;

	screen.close();
	
	return 0;
}

