//============================================================================
// Name        : Game.cpp
// Author      : Amass
// Version     :
// Copyright   : Public For devs
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>


	#include "Game.h"

using std::cout;
using std::endl;


Game *Window = nullptr;

int main(int argc, char* argv[]) {

	const int fpsLimit = 1000/60;

	cout << "hello world" << endl;
	cout << "Shut up compiler, no fricking errors" << endl;


/*
	unsigned int red = 255;
	unsigned int green = 128;
	unsigned int blue = 255;
*/



Window = new Game();
int takenTime;
Uint32 startCount;

	Window->init("ScyPhy", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			Game::WINDOW_WIDTH, Game::WINDOW_HEIGHT, false);

while (Window->running())
	{
startCount = SDL_GetTicks();
	Window->handleEvent();


		//Window.modColor((unsigned int)red, (unsigned int)green, (unsigned int)blue);


	Window->update();

	Window->render();

//red--;	green--;	blue--;

takenTime = SDL_GetTicks() - startCount;
	if(fpsLimit > takenTime)	SDL_Delay(fpsLimit-takenTime);
	}
	Window->clean();

	return 0;
}
