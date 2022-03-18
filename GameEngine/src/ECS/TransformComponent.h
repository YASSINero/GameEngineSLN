/*
 * TransformComponent.h
 *
 *  Created on: 19 Feb 2022
 *      Author: Amass
 */

#ifndef ECS_TransformComponent_H_
#define ECS_TransformComponent_H_

#include "Components.h"
#include "../Vector2D.h"


class TransformComponent : public Component
{


public:
	Vector2D position;
	Vector2D velocity;

	int trans_cpnHeight = 32;
	int trans_cpnWidth = 32;

	int scale = 3;
	int speed = 3;

public:
	TransformComponent()
	{
		position.m_x = 320;	position.m_y = 400;
	}

	TransformComponent(int sc): scale(sc)
	{
		position.m_x = 320;	position.m_y = 400;
	}

	TransformComponent(float x, float y)
	{
		position.m_x = x;
		position.m_y = y;
	}

	TransformComponent(float x, float y, int h, int w, int sc): trans_cpnHeight(h), trans_cpnWidth(w)
	{
		position.m_x = x;
		position.m_y = y;
	}


//	int x() {return xpos;}
//	int y() {return ypos;}

	void cpnInit() override
	{
		velocity.Zero();
	}



	void cpnUpdate() override
	{



		
/*
		position.m_x += velocity.m_x * speed;
		position.m_y += velocity.m_y * speed;
	sinewave
		position.m_x = (unsigned int)((1+sin(Game::counter * 0.01)) * (Game::WINDOW_WIDTH/2));
		position.m_y = (unsigned int)((1+sin(Game::counter * 0.05)) * 15);
*/
	}
};



#endif /* ECS_TransformComponent_H_ */
