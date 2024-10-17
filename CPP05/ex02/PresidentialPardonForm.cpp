#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): _target(target), AForm("Presidential Pardon Form", 25, 5) {}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy): _target(copy._target), AForm(copy) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src) {
	if (this != &src) {
		_target = src._target;
	}
	return *this;
}

void	PresidentialPardonForm::execution() const {
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}