/*
 * Collision.h
 *
 *  Created on: 23 Feb 2022
 *      Author: Amass
 */

#ifndef COLLISION_H_
#define COLLISION_H_

#include <SDL.h>
#include "ECS/CollisionComponent.h"







class Collision
{
public:



	static bool AABB(const SDL_Rect& rectA, const SDL_Rect& rectB);	// Access Aligned Bounding Box
	static bool collidersAABB(const CollisionComponent& colA, const CollisionComponent& colB);

};



#endif /* COLLISION_H_ */
