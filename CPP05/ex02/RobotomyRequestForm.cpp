#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(std::string target): _target(target), AForm("Robotomy Request Form", 72, 45) {}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy): _target(copy._target), AForm(copy) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src) {
	if (this != &src) {
		_target = src._target;
	}
	return *this;
}

void	RobotomyRequestForm::execution() const {
	std::cout << "***Buzzzzzzzz, ***drillllllllllllll, ***whirrrrrrrr" << std::endl;
	if (rand() %2) {
		std::cout << _target << " has been robotomized successfully" << std::endl;
	} else {
		std::cout << "The robotomy failed" << std::endl;
	}
}