/*
 * Vector2D.h
 *
 *  Created on: 20 Feb 2022
 *      Author: Amass
 */

#ifndef VECTOR2D_H_
#define VECTOR2D_H_

#include <iostream>

struct Vector2D
{
	float m_x,m_y;

public:

	Vector2D();
	Vector2D(float x, float y);



	Vector2D& add(const Vector2D& vec);
	Vector2D& subtract(const Vector2D& vec);
	Vector2D& multiply(const Vector2D& vec);
	Vector2D& divide(const Vector2D& vec);

	friend Vector2D& operator+(Vector2D& vec1, const Vector2D& vec2);
	friend Vector2D& operator-(Vector2D& vec1, const Vector2D& vec2);
	friend Vector2D& operator*(Vector2D& vec1, const Vector2D& vec2);
	friend Vector2D& operator/(Vector2D& vec1, const Vector2D& vec2);

		Vector2D& operator+=(const Vector2D& vec);
		Vector2D& operator-=(const Vector2D& vec);
		Vector2D& operator*=(const Vector2D& vec);
		Vector2D& operator/=(const Vector2D& vec);


		Vector2D& operator*(const int& i);
	 Vector2D& Zero();
};



#endif /* VECTOR2D_H_ */
