#include <iostream>
#include "./Harl.hpp"

int main ()
{
	Harl test;

	std::cout << "Debug:" << std::endl;
	test.complain("DEBUG");

	std::cout << std::endl;
	test.complain("COMPLAIN");

	std::cout << "\nInfo:" << std::endl;
	test.complain("INFO");

	std::cout << std::endl;
	test.complain("Info");

	std::cout << "\nWarning:" << std::endl;
	test.complain("WARNING");

	std::cout << std::endl;
	test.complain("");

	std::cout << "\nError:" << std::endl;
	test.complain("ERROR");
}