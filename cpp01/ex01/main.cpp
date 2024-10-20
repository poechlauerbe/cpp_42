#include <iostream>
#include "./Zombie.hpp"

int main ()
{
	Zombie	*testZombie = NULL;
	int n1 = 10;

	testZombie = zombieHorde(0, "Number One");
	if (!testZombie)
		std::cout << "no Zombie created" << std::endl;

	testZombie = zombieHorde(n1, "testZombie");
	if (!testZombie)
		return 1;
	for (int i = 0; i < n1; i++)
		testZombie[i].announce();
	delete [] testZombie;
}
