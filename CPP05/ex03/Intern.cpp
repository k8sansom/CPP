#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& copy) {
    (void)copy;
}

Intern& Intern::operator=(const Intern& src) {
    (void)src;
    return *this;
}

Intern::~Intern() {}

// Exception for form not found
const char* Intern::FormNotFound::what() const throw() {
    return "Form not found";
}

// The makeForm function now uses function pointers for cleaner code
AForm* Intern::makeForm(const std::string &formName, const std::string &target) {
    // Array of form names
    std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    
    // Array of function pointers for creating forms
    AForm* (*formCreators[3])(const std::string&) = {
        [](const std::string &target) -> AForm* { return new ShrubberyCreationForm(target); },
        [](const std::string &target) -> AForm* { return new RobotomyRequestForm(target); },
        [](const std::string &target) -> AForm* { return new PresidentialPardonForm(target); }
    };
    
    // Iterate over form names to find the correct form
    for (int i = 0; i < 3; ++i) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return formCreators[i](target);  // Call the corresponding form creation function
        }
    }
    std::cout << "Intern cannot create " << formName << ", reason:" << std::endl;
    throw Intern::FormNotFound();
}
