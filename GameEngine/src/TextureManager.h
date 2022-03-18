/*
 * TextureManager.h
 *
 *  Created on: 14 Feb 2022
 *      Author: Amass
 */

#ifndef TEXTUREMANAGER_H_
#define TEXTUREMANAGER_H_

#include <SDL.h>
#include <SDL_image.h>
#include "Game.h"



class TextureManager {
	
public:
	TextureManager();
	static SDL_Texture* loadTexture(const char* filePath);
	static void draw(SDL_Texture* textureDraw, SDL_Rect srcRectDraw, SDL_Rect destRectDraw, SDL_RendererFlip flip);
};



#endif /* TEXTUREMANAGER_H_ */
