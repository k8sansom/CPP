# ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &copy);
		WrongAnimal& operator=(const WrongAnimal &src);
		~WrongAnimal();

		void		makeSound(void) const;
		std::string	getType(void) const;
	protected:
		std::string	_type;
};

#endif