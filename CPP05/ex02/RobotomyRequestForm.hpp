#ifndef RobotomyRequestForm_HPP
#define RobotomyRequestForm_HPP

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm: public AForm {
private:
	std::string	_target;

public:
	RobotomyRequestForm(std::string target);
	~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& copy);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& src);

	void	execution() const;
};


#endif