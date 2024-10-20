#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource() {}

IMateriaSource::IMateriaSource(const IMateriaSource& other) {
	(void) other;
}

IMateriaSource& IMateriaSource::operator=(const IMateriaSource& other) {
	if (this == &other)
		return *this;
	return *this;
}

IMateriaSource::~IMateriaSource() {}
