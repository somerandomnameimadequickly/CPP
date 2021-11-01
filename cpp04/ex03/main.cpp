#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main() {
	std::cout << "1" << std::endl;
	IMateriaSource* src = new MateriaSource();
	std::cout << "2" << std::endl;
	src->learnMateria(new Ice());
	std::cout << "3" << std::endl;
	src->learnMateria(new Cure());
	std::cout << "4" << std::endl;
	ICharacter* me = new Character("me");
	std::cout << "5" << std::endl;
	AMateria* tmp;
	std::cout << "6" << std::endl;
	tmp = src->createMateria("ice");
	std::cout << "7" << std::endl;
	me->equip(tmp);
	std::cout << "8" << std::endl;
	tmp = src->createMateria("cure");
	std::cout << "9" << std::endl;
	me->equip(tmp);
	std::cout << "10" << std::endl;
	ICharacter* bob = new Character("bob");
	std::cout << "11" << std::endl;
	me->use(0, *bob);
	std::cout << "12" << std::endl;
	me->use(1, *bob);
	std::cout << "13" << std::endl;
	delete bob;
	delete me;
	delete src;
	return 0;
}