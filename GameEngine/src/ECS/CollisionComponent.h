/*
 * CollisionComponent.h
 *
 *  Created on: 23 Feb 2022
 *      Author: Amass
 */

#ifndef ECS_COLLISIONCOMPONENT_H_
#define ECS_COLLISIONCOMPONENT_H_

#include <string>
#include <SDL.h>
#include "Components.h"

class CollisionComponent : public Component
{
public:
	SDL_Rect Collider;
	std::string tag;

	TransformComponent* transform;

public:

	CollisionComponent(std::string Tag): tag(Tag) {} // @suppress("Class members should be properly initialized")

	void cpnInit() override
	{
		if(entity->hasComponent<TransformComponent>() == false)	entity->addComponent<TransformComponent>();


			std::cout << "Cpn added" << std::endl;

		transform = &entity->getComponent<TransformComponent>();

		Game::globalColliders.push_back(this);

	}

void cpnUpdate() override
{

	Collider.x = static_cast<int>(transform->position.m_x);
	Collider.y = static_cast<int>(transform->position.m_y);

	Collider.h = transform->trans_cpnHeight * transform->scale;
	Collider.w = transform->trans_cpnWidth * transform->scale;

}


};





#endif /* ECS_COLLISIONCOMPONENT_H_ */
