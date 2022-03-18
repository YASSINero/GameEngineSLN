/*
 * Collision.cpp
 *
 *  Created on: 23 Feb 2022
 *      Author: Amass
 */

//#include <iostream>
#include "Collision.h"
//#include "ECS/Components.h"
//#include "ECS/CollisionComponent.h"		// TODO This bitch here is causing the multiple definitions error

bool Collision::AABB(const SDL_Rect& rectA, const SDL_Rect& rectB)
{


//std::cout << rectA.x << " " << rectB.x << " " << rectA.y << " " << rectB.y << " " << rectA.h << " " << rectA.w << " " << rectB.h << " " << rectB.w << std::endl;

				return(rectA.x + rectA.w >= rectB.x &&
					rectB.x + rectB.w >= rectA.x &&
					rectA.y + rectA.h >= rectB.y &&
					rectB.y + rectB.h >= rectA.y);

		//	std::cout << rectA.x << " " << rectB.x << " " << rectA.y << " " << rectB.y << " " << rectA.h << " " << rectA.w << " " << rectB.h << " " << rectB.w << std::endl;

}

bool Collision::collidersAABB(const CollisionComponent& colA, const CollisionComponent& colB)
{

	if (AABB(colA.Collider, colB.Collider) == true)
	{
			//std::cout << colA.tag << " hit " << colB.tag << std::endl;
		return true;
	}
	else
	{
		return false;
	}
}
