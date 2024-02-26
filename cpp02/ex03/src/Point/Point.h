/// @file   Point.h
/// @author minakim
/// @date   26-Feb-2024

#ifndef Point_H
#define Point_H

/// @library
#include "Fixed/Fixed.h"

/// @macro
/// valid

/// @class Point
class Point {
public:
	Point(void);
	Point(Fixed other);
	Point(const float x, const float y);
	Point(const Fixed x, const Fixed y);
	~Point(void);
	Point	&operator=(const Point &other);
	Point	operator-(const Point &other);
	Fixed 	getX(void) const;
	Fixed	getY(void) const;

private:
	Fixed	_x;
	Fixed	_y;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif