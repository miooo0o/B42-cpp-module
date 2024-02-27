/// @file   Point.h
/// @author minakim
/// @date   26-Feb-2024

#ifndef Point_H
#define Point_H

/// @library
#include "Fixed/Fixed.h"

///	@enum
typedef enum e_sign {
	POSITIVE = 0,
	NEGATIVE
} e_sign;

/// @class Point
class Point {
public:
	Point(void);
	Point(Point const &other);
	Point(const float x, const float y);
	Point(const Fixed x, const Fixed y);
	~Point(void);
	Point	&operator=(const Point &other);
	Point	operator-(const Point &other) const;

	Fixed 	getX(void) const;
	Fixed	getY(void) const;

private:
	Fixed	_x;
	Fixed	_y;
};

bool	bsp(Point const& a, Point const& b, Point const& c, Point const& point);

#endif