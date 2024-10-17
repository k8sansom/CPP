#ifndef SHRUBBERYCREATIONForm_HPP
#define SHRUBBERYCREATIONForm_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm: public AForm {
private:
	std::string	_target;

public:
	ShrubberyCreationForm(std::string target);
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& copy);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& src);

	void	execution() const;
};


#endif