#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource() {
	for (int i = 0; i < this->_size; i++) {
		this->_memory[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& other) : IMateriaSource(other)  {
	for (int i = 0; i < this->_size; i++) {
		if (other.getMemory(i)) {
			this->_memory[i] = (other.getMemory(i))->clone();
		} else {
			this->_memory[i]  = NULL;
		}
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	if (this == &other)
		return *this;

	// delete it if something is stored
	for (int i = 0; i < this->_size; i++) {
		if (this->_memory[i]) {
			delete (this->_memory[i]);
		}
	}

	// fill it with the values of other
	for (int i = 0; i < this->_size; i++) {
		if (other._memory[i]) {
			this->_memory[i] = other._memory[i]->clone();
		} else {
			this->_memory[i] = NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < this->_size; i++) {
		if (this->_memory[i]) {
			delete this->_memory[i];
		}
	}
}

AMateria*	MateriaSource::getMemory(int idx) const {
	if (idx < 0 || idx >= _size)
		return NULL;
	return this->_memory[idx];
}

void MateriaSource::learnMateria(AMateria* materia) {
	for (int i = 0; i < this->_size; i++) {
		if (!this->_memory[i]) {
			this->_memory[i] = materia;
			return;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < this->_size; i++) {
		if (this->_memory[i]->getType() == type) {
			return this->_memory[i]->clone();
		}
	}
	return NULL;
}
