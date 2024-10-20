#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(float x, float y) : _x(x), _y(y) {}

Point::Point(const Point& other) : _x(other._x), _y(other._y) {}

Point& Point::operator=(const Point&)
{
	return *this;
}

Point::~Point() {}

Fixed Point::get_x() const
{
	return this->_x;
}

Fixed Point::get_y() const
{
	return this->_y;
}

int Point::getRawX() const
{
	return this->_x.getRawBits();
}

int Point::getRawY() const
{
	return this->_y.getRawBits();
}
