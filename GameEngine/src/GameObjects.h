/*
 * GameObjects.h
 *
 *  Created on: 14 Feb 2022
 *      Author: Amass
 */

#ifndef GAMEOBJECTS_H_
#define GAMEOBJECTS_H_

#include <SDL.h>
#include <SDL_image.h>
#include "TextureManager.h"



class GameObjects {


	SDL_Texture* GO_m_texture;
	SDL_Rect GO_srcRect, GO_destRect;

int m_GO_x, m_GO_y;
public:
	GameObjects(const char* GO_filePath, int& GO_x, int& GO_y);

	void update(int main_x, int main_y);
	void render();

};



#endif /* GAMEOBJECTS_H_ */
