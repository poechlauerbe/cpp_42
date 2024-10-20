#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
	private:
		// Add member variables here

	public:
		Cure();
		Cure(const Cure& other);
		Cure& operator=(const Cure& other);
		~Cure();
		
		AMateria* clone() const;
		void use(ICharacter& target);

};

#endif
