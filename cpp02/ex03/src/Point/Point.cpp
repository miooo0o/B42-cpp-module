/// @file   Point.cpp
/// @author minakim
/// @date   26-Feb-2024

#include "Point.h"


/// @brief	constructor
Point::Point(void)
	: _x(0), _y(0)
{
}

Point::Point(Fixed other)
{
	*this = other;
}

Point::Point(const float x, const float y)
	: _x(Fixed(x)), _y(Fixed(y))
{
}

Point::Point(const Fixed x, const Fixed y)
	: _x(Fixed(x)), _y(Fixed(y))
{
}

/// @brief	destructor
Point::~Point(void)
{
}

/// @brief	operator
Point &Point::operator=(const Point &other)
{
	if (this != &other)
	{
		_x = other.getX();
		_y = other.getY();
	}
	return (*this);
}

Point	Point::operator-(const Point &other)
{
	return Point(_x - other._x, _y - other._y);
}

/// @brief	public
Fixed 	Point::getX(void) const
{
	return (_x);
}

Fixed 	Point::getY(void) const
{
	return (_y);
}

///	@brief	BSP
bool	bsp(Point const a, Point const b, Point const c, Point const point)
{

}