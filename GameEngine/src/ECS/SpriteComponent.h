/*
 * SpriteComponent.h
 *
 *  Created on: 19 Feb 2022
 *      Author: Amass
 */

#ifndef ECS_SPRITECOMPONENT_H_
#define ECS_SPRITECOMPONENT_H_

#include "Components.h"
#include "SDL.h"
#include "../TextureManager.h"
#include "Animation.h"
#include <map>

class SpriteComponent : public Component
{
	TransformComponent* transform;
	SDL_Texture* spriteTexture;
	SDL_Rect srcRect, destRect;

private:
	bool animated = false;
	int duration = 100, frames = 0;
	

public:

	int animIndex = 0;
	std::map<const char*, Animation> animations;

public:
	SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;
	SpriteComponent() = default;
	SpriteComponent(const char* path)
	{
SetTex(path);
	}

	SpriteComponent(const char* path, bool isAnimated) : animated(isAnimated)
	{
		Animation idle = Animation(1, 3, 100);
		Animation walk = Animation(0, 6, 100);

		animations.emplace("idle", idle);
		animations.emplace("walk", walk);

		Play("idle");

		SetTex(path);
	}

	~SpriteComponent()
	{
		SDL_DestroyTexture(spriteTexture);
	}



void cpnInit() override
{


	transform = &entity->getComponent<TransformComponent>();

srcRect.x = srcRect.y = 0;

srcRect.h = transform->trans_cpnHeight;
srcRect.w = transform->trans_cpnWidth;

}

void cpnUpdate() override
{
	if(animated)	srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / duration) % frames);

	srcRect.y = animIndex * transform->trans_cpnHeight;

destRect.x = static_cast<int>(transform->position.m_x);
destRect.y = static_cast<int>(transform->position.m_y);

destRect.h = transform->trans_cpnHeight * transform->scale;
destRect.w = transform->trans_cpnWidth * transform->scale;

}

void cpnDraw() override
{
	TextureManager::draw(spriteTexture, srcRect, destRect, spriteFlip);
}

void SetTex(const char* altPath)
{
	spriteTexture = TextureManager::loadTexture(altPath);
}

void Play(const char* animName)
{
	frames = animations[animName].frames;
	animIndex = animations[animName].index;
	duration = animations[animName].speed;
}

};



#endif /* ECS_SPRITECOMPONENT_H_ */
