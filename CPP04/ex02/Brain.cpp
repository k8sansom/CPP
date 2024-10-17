#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor called" << std::endl;
}
Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain& copy) {
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
        _ideas[i] = copy._ideas[i];
}

Brain& Brain::operator=(const Brain& src) {
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &src) {
		for (int i = 0; i < 100; i++)
			_ideas[i] = src._ideas[i];
	}
	return (*this);
}

void Brain::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100) {
        _ideas[index] = idea;
    }
}

std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100) {
        return (_ideas[index]);
    }
    return "";
}