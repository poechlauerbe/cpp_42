#include "./Point.hpp"
#include <cstdlib>

static long	crossProduct(const Point& p1, const Point& p2, const Point& point)
{
	// create vector 1 and vector 2:
	long v1x = p2.getRawX() - p1.getRawX();
	long v1y = p2.getRawY() - p1.getRawY();
	long v2x = point.getRawX() - p1.getRawX();
	long v2y = point.getRawY() - p1.getRawY();

	// return cross product:
	return (v1x * v2y - v1y * v2x);
}

static long triAreaTotal(const Point& a, const Point& b, const Point& c)
{
	long	area;

	// Area A = [x1(y2 – y3) + x2(y3 – y1) + x3(y1-y2)]/2
	area = std::abs(a.getRawX() * (b.getRawY() - c.getRawY()) + b.getRawX() * (c.getRawY() - a.getRawY()) + c.getRawX() * (a.getRawY() - b.getRawY()));
	return area;

}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	long area1;
	long area2;

	if ((!crossProduct(a, b, point) || !crossProduct(b, c, point) || !crossProduct(c, a, point)))
		return false;

	area1 = triAreaTotal(a, b, c);
	area2 = triAreaTotal(point, a, b) + triAreaTotal(point, b, c) + triAreaTotal(point, c, a);
	if (area1 == area2)
		return true;
	return false;
}
