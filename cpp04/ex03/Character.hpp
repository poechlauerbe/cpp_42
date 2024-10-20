#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
	private:
		AMateria* 			_inventory[_size];

	public:
		Character();
		Character(std::string name);
		Character(const Character& other);
		Character& operator=(const Character& other);
		~Character();

		AMateria*	getAMateria(int idx) const;

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif
