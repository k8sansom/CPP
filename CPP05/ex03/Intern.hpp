#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
public:
    Intern();
    Intern(const Intern &copy);
    Intern& operator=(const Intern &copy);
    ~Intern();

    AForm* makeForm(const std::string &formName, const std::string &target);
	class FormNotFound : public std::exception {
        public:
            const char *what() const throw();
    };
    
	private:
};

#endif
