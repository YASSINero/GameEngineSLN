/*
 * GameObjects.cpp
 *
 *  Created on: 14 Feb 2022
 *      Author: Amass
 */

#include "GameObjects.h"



GameObjects::GameObjects(const char* GO_filePath, int& GO_x, int& GO_y): m_GO_x(GO_x), m_GO_y(GO_y)
{


	GO_m_texture = TextureManager::loadTexture(GO_filePath);

}

void GameObjects::update(int main_x, int main_y)
{
GO_srcRect.x = 0;
GO_srcRect.y = 0;
GO_srcRect.h = 32;
GO_srcRect.w = 32;

GO_destRect.x = main_x;
GO_destRect.y = main_y;

GO_destRect.h = GO_srcRect.h * 4;
GO_destRect.w = GO_srcRect.w * 4;
}

void GameObjects::render()
{
	SDL_RenderCopy(Game::globalRenderer, GO_m_texture, &GO_srcRect, &GO_destRect);
}

