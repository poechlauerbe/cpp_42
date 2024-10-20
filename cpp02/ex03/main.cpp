#include <iostream>
#include "./Point.hpp"


int main() {

	Point a(0, 0);
	Point b(0, 10);
	Point c(4, 0);
	Point point(0, 10);
	Point point1(0, 0);
	Point point2(4, 0);
	Point point3(0.002, 9.5);

	std::cout << std::boolalpha;
	std::cout << "Point: " << bsp(a, b, c, point) << std::endl;
	std::cout << "Point1: " << bsp(a, b, c, point1) << std::endl;
	std::cout << "Point2: " << bsp(a, b, c, point2) << std::endl;
	std::cout << "Point3: " << bsp(a, b, c, point3) << std::endl;
	return 0;
}
