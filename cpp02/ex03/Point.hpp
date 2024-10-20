#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
	private:
		const Fixed _x;
		const Fixed _y;

	public:
		Point();
		Point(float x, float y);

		Point(const Point& other);
		Point& operator=(const Point&);

		~Point();

		Fixed get_x() const;
		Fixed get_y() const;
		int		getRawX() const;
		int		getRawY() const;

};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
