/*
 * KeyboardController.h
 *
 *  Created on: 21 Feb 2022
 *      Author: Amass
 */

#ifndef KEYBOARDCONTROLLER_H_
#define KEYBOARDCONTROLLER_H_

#include "../Game.h"
#include "Components.h"

class KeyboardController : public Component
{
public:
	TransformComponent* transform;
	SpriteComponent* sprite;

public:

	void cpnInit() override
	{
		transform = &entity->getComponent<TransformComponent>();
		sprite = &entity->getComponent<SpriteComponent>();
	}

	void cpnUpdate()
	{
		if(Game::event.type == SDL_KEYDOWN)
		{
			switch (Game::event.key.keysym.sym)
				{
				case SDLK_z:
					transform->velocity.m_y = -1;
					sprite->Play("walk");
					break;
				case SDLK_q:
					transform->velocity.m_x = -1;
					sprite->Play("walk");	sprite->spriteFlip = SDL_FLIP_HORIZONTAL;
					break;
				case SDLK_s:
					transform->velocity.m_y = 1;
					sprite->Play("walk");
					break;
				case SDLK_d:
					transform->velocity.m_x = 1;
					sprite->Play("walk");	sprite->spriteFlip = SDL_FLIP_NONE;
					break;
				case SDLK_ESCAPE:
					Game::isRunning = false;
					break;
				default:
					break;
				}
		}



		if(Game::event.type == SDL_KEYUP)
		{
			switch (Game::event.key.keysym.sym)
				{
							case SDLK_z:
								transform->velocity.m_y = 0;
								sprite->Play("idle");
								break;
							case SDLK_q:
								transform->velocity.m_x = 0;
								sprite->spriteFlip = SDL_FLIP_HORIZONTAL;
								sprite->Play("idle");	
								break;
							case SDLK_s:
								transform->velocity.m_y = 0;
								sprite->Play("idle");
								break;
							case SDLK_d:
								transform->velocity.m_x = 0;
								sprite->Play("idle");
								break;
							default:
								break;
				}
		}


	}
};



#endif /* KEYBOARDCONTROLLER_H_ */
