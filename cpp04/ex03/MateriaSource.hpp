#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource {
	private:
		AMateria* 			_memory[_size];

	public:
		MateriaSource();
		MateriaSource(const MateriaSource& other);
		MateriaSource& operator=(const MateriaSource& other);
		~MateriaSource();

		AMateria*	getMemory(int idx) const;

		void		learnMateria(AMateria* materia);
		AMateria*	createMateria(std::string const & type);
};

#endif
