/*
 * Vector2D.cpp
 *
 *  Created on: 20 Feb 2022
 *      Author: Amass
 */

#include "Vector2D.h"

Vector2D::Vector2D(): m_x(0.0f), m_y(0.0f)
{}

Vector2D::Vector2D(float x, float y): m_x(x), m_y(y)
{}

Vector2D& Vector2D::add(const Vector2D& vec)
{
	this->m_x += vec.m_x;
	this->m_y += vec.m_y;
	return *this;
}

Vector2D& Vector2D::subtract(const Vector2D& vec)
{
	this->m_x -= vec.m_x;
	this->m_y -= vec.m_y;
	return *this;
}

Vector2D& Vector2D::multiply(const Vector2D& vec)
{
	this->m_x *= vec.m_x;
	this->m_y *= vec.m_y;
	return *this;
}

Vector2D& Vector2D::divide(const Vector2D& vec)
{
	this->m_x /= vec.m_x;
	this->m_y /= vec.m_y;
	return *this;
}

//============operators overloading============

Vector2D& operator+(Vector2D& vec1, const Vector2D& vec2)
{
return	vec1.add(vec2);
}

Vector2D& operator-(Vector2D& vec1, const Vector2D& vec2)
{
return	vec1.subtract(vec2);
}

Vector2D& operator*(Vector2D& vec1, const Vector2D& vec2)
{
return	vec1.multiply(vec2);
}

Vector2D& operator/(Vector2D& vec1, const Vector2D& vec2)
{
return	vec1.divide(vec2);
}

//***************operator overloading v2********

Vector2D& Vector2D::operator *(const int& i)
{
	this->m_x *= i;
	this->m_y *= i;
	return *this;
}


//==============equal operators overloading========

Vector2D& Vector2D::operator+=(const Vector2D& vec)
{
return this->add(vec);
}

Vector2D& Vector2D::operator-=(const Vector2D& vec)
{
return this->subtract(vec);
}

Vector2D& Vector2D::operator*=(const Vector2D& vec)
{
return this->multiply(vec);
}

Vector2D& Vector2D::operator/=(const Vector2D& vec)
{
return this->divide(vec);
}


//=================Zero=========================

Vector2D& Vector2D::Zero()
{
	this->m_x = 0.0f;
	this->m_y = 0.0f;
	return *this;
}


