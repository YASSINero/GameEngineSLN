/*
 * Game.h
 *
 *  Created on: 10 Feb 2022
 *      Author: Amass
 */

#ifndef GAME_H_
#define GAME_H_

#include <SDL.h>
#include <SDL_image.h>
#include <cmath>
#include <vector>



class CollisionComponent;

class Game {
	SDL_Window* m_Window;
	SDL_Texture* m_Texture;

//int sinWave_x, sinWave_y;





//	Uint32 *m_Buffer;

	


public:
	const static int WINDOW_HEIGHT = 640;
	const static int WINDOW_WIDTH = 800;
	//static double counter;
	static SDL_Renderer* globalRenderer;
	static SDL_Event event;
	static std::vector<CollisionComponent*> globalColliders;
	static bool isRunning;

public:
	static void addTile(int srcX, int srcY, int xpos, int ypos);


public:
	Game();
	~Game();

	void init(const char* title, int x, int y, int winWIDTH, int winHEIGHT, bool isFullscreen);
	void handleEvent();
	void update();
	void render();
	void clean();
	
	//void modColor(Uint8 red, Uint8 green, Uint8 blue);

	bool running()	{return isRunning;}
	static int elapsed() {return SDL_GetTicks();}



};





#endif /* GAME_H_ */
