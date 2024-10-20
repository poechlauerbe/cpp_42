#include <iostream>

#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

AMateria* floor = NULL;

// make a linked list and sotre the AMateria
void	preUnequip(Character* ptr, int idx) {
	if (!ptr->getAMateria(idx))
		return;
	if (!floor) {
		floor = ptr->getAMateria((idx));
		floor->next = NULL;
		return ;
	}
	AMateria* temp = floor;
	while (temp->next)
		temp = temp->next;
	temp->next = ptr->getAMateria(idx);
	temp->next->next = NULL;
}

void	deleteFloor() {
	AMateria* temp = floor;
	while (temp) {
		temp = temp->next;
		delete floor;
		floor = temp;
	}
}

int main () {
	{
		std::cout << "\ntest1" << std::endl;
		AMateria* test = new Cure;
		if (!test)
			return 1;
		AMateria* newOne = NULL;
		Character chara("Ferdl");

		newOne = test->clone();
		if (!newOne)
			return (delete test, 1);

		std::cout << "Type of test: " << test->getType() << std::endl;
		std::cout << "Type of newOne: " << newOne->getType() << std::endl;

		newOne->use(chara);
		chara.equip(test);
		chara.equip(newOne);
		Character	chara2("Hansi");
		chara2 = chara;
		preUnequip(&chara, 0);
		chara.unequip(0);
		preUnequip(&chara, 1);
		chara.unequip(1);
		deleteFloor();

		chara2.use(1, chara);

	}

	{
		std::cout << "\ntest2 (subject)" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}
}
