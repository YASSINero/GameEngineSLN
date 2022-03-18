/*
 * TileComponent.h
 *
 *  Created on: 28 Feb 2022
 *      Author: Amass
 */

#ifndef ECS_TILECOMPONENT_H_
#define ECS_TILECOMPONENT_H_

#include "SDL.h"
#include "ECS.h"



class TileComponent : public Component
{
public:
	SDL_Texture* texture;
	SDL_Rect srcR, destR;

	

public:
	TileComponent() = default;

	~TileComponent()
	{
		SDL_DestroyTexture(texture);
	}

	TileComponent(int srcX, int srcY, int xpos, int ypos, const char* path): texture(nullptr)
	{
		texture = TextureManager::loadTexture(path);
		
		srcR.y = srcY;	srcR.x = srcX;	srcR.w = srcR.h = 32;

		destR.x = xpos;	destR.y = ypos;	destR.w = destR.h = 64;

		
	}

	void cpnDraw()	override
	{

		TextureManager::draw(texture, srcR, destR, SDL_FLIP_NONE);

	}

};

#endif /* ECS_TILECOMPONENT_H_ */
