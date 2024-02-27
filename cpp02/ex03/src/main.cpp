/// @file   main.cpp
/// @author minakim
/// @date   18-Feb-2024

#include "Point/Point.h"

int	bsp_checker(Point const& a, Point const& b, Point const& c, Point const& point)
{
	std::cout << "Point (" << point.getX() << ", " << point.getY() << ") is ";
	if (bsp(a, b, c, point) && bsp(b, a, c, point) && \
			bsp(c, b, a, point) && bsp(b, c, a, point))
	{
		std::cout << "point inside the triangle."<< std::endl;
		return (VALID);
	}
	else if (!bsp(a, b, c, point) && !bsp(b, a, c, point) && \
			!bsp(c, b, a, point) && !bsp(b, c, a, point))
	{
		std::cout << "point outside the triangle."<< std::endl;
		return (VALID);
	}
	std::cout << "test fail.\n"<< std::endl;
	return (INVALID);
}

///	@note	My First Class inOrthodox Canonical Form
///	Fixed-point numbers
int main(void)
{
	Point	a(0.0f, 0.0f);
	Point	b(2.0f, 5.0f);
	Point	c(10.0f, 3.0f);
	Point	point_inside(3.0f, 3.0f);
	Point	point_outside(5.0f, 7.0f);
	Point	point_vertex(10.0f, 3.0f);
	Point	point_edge(6.0f, 6.0f);
	
	std::cout << "BSP Test: Triangle ABC" << std::endl << std::endl;
	std::cout << "Test Case 1: Point inside triangle" << std::endl;
	std::cout << "Point A(" << a.getX() << ", " << a.getY() << "), "
				<< "B(" << b.getX() << ", " << b.getY() << "), "
				<< "C(" << c.getX() << ", " << c.getY() << ")"
				<< std::endl;
	bsp_checker(a, b, c, point_inside);
	std::cout << std::endl;
	std::cout << "Test Case 2: Point outside triangle" << std::endl;
	std::cout << "Point A(" << a.getX() << ", " << a.getY() << "), "
				<< "B(" << b.getX() << ", " << b.getY() << "), "
				<< "C(" << c.getX() << ", " << c.getY() << ")"
				<< std::endl;
	bsp_checker(a, b, c, point_outside);
	std::cout << std::endl;
	std::cout << "Test Case 3: Point on vertex of triangle" << std::endl;
	std::cout << "Point A(" << a.getX() << ", " << a.getY() << "), "
			  << "B(" << b.getX() << ", " << b.getY() << "), "
			  << "C(" << c.getX() << ", " << c.getY() << ")"
			  << std::endl;
	bsp_checker(a, b, c, point_vertex);
	std::cout << std::endl;
	std::cout << "Test Case 4: Point on edge" << std::endl;
	std::cout << "Point A(" << a.getX() << ", " << a.getY() << "), "
			  << "B(" << b.getX() << ", " << b.getY() << "), "
			  << "C(" << c.getX() << ", " << c.getY() << ")"
			  << std::endl;
	bsp_checker(a, b, c, point_edge);
	return (EXIT_SUCCESS);
}