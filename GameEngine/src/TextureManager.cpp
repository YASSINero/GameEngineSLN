/*
 * TextureManager.cpp
 *
 *  Created on: 14 Feb 2022
 *      Author: Amass
 */

#include "TextureManager.h"



TextureManager::TextureManager() {
	// TODO Auto-generated constructor stub

}

SDL_Texture* TextureManager::loadTexture(const char* filePath)
{
	SDL_Surface* tempSurface = IMG_Load(filePath);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::globalRenderer, tempSurface);

	SDL_FreeSurface(tempSurface);
return texture;
}

void TextureManager::draw(SDL_Texture* textureDraw, SDL_Rect srcRectDraw, SDL_Rect destRectDraw, SDL_RendererFlip Flip)
{
SDL_RenderCopyEx(Game::globalRenderer, textureDraw, &srcRectDraw, &destRectDraw, NULL, NULL, Flip);
}

