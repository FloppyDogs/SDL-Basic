#include <iostream>
#include <SDL.h>
#include "Screen.h"

using namespace std;


int main(int argc, char* args[]) {

	Screen screen;

	if (screen.init() == false) {
		cout << "Error initializing SDL." << endl;
	}

	while (true) {

		if (screen.processEvents() == false) {
			break;
		}
		
	}
	
	screen.close();
	
	return 0;
}

