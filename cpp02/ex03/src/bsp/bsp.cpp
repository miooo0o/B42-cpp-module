/// @file   bsp.cpp
/// @author minakim
/// @date   27-Feb-2024

#include "Point/Point.h"

///	@brief	BSP
e_sign	cross_product(Point const v1, Point const v2)
{
	Fixed	res(0);
	
	res = v1.getX() * v2.getY() - (v1.getY() * v2.getX());
	if (res == 0)
		return (SIGN_ZERO);
	return ((res > 0) ? SIGN_POSITIVE : SIGN_NEGATIVE);
}

bool	is_point_vertices(Point const a, Point const b, Point const c, Point const point)
{
	if (a == point || b == point || c == point)
		return (true);
	return (false);
}

bool is_point_on_edge(Point const a, Point const b, Point const point)
{
	if (cross_product(b - a, point - a) != SIGN_ZERO)
		return (false);
	return (true);
}

bool is_point_on_edges(Point const a, Point const b, Point const c, Point const point)
{
	if (is_point_on_edge(a, b, point) || is_point_on_edge(b, c, point) ||
		is_point_on_edge(c, a, point))
		return (true);
	return (false);
}

int	validate_point(Point const a, Point const b, Point const c, Point const point)
{
	if (is_point_vertices(a, b, c, point) && is_point_on_edges(a, b, c, point))
		return (INVALID);
	return (VALID);
}

///	@brief	Returns: True if the point is inside the triangle. False otherwise.
/// Thus, if the point is a vertex or on edge, it will return False.

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (validate_point(a, b, c, point) != VALID)
		return (false);
	return (cross_product(b - a, point - a) == cross_product(c - b, point - b) &&
			cross_product(c - b, point - b) == cross_product(a - c, point - c));
}
