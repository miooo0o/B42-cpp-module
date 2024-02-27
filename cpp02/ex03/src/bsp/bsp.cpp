/// @file   bsp.cpp
/// @author minakim
/// @date   27-Feb-2024

#include "Point/Point.h"

///	@brief	BSP
e_sign	cross_product(Point const v1, Point const v2)
{
	Fixed	res(0);
	
	res = v1.getX() * v2.getY() - (v1.getY() * v2.getX());
	return ((res >= 0) ? POSITIVE : NEGATIVE);
}

bool	bsp(Point const& a, Point const& b, Point const& c, Point const& point)
{
	return (cross_product(b - a, point - a) == cross_product(c - b, point - b) &&
			cross_product(c - b, point - b) == cross_product(a - c, point - c));
}
