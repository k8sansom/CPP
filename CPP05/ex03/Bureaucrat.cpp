#include "Bureaucrat.hpp"

const char	*Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade too low!");
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _grade(grade), _name(name) {
	if (grade < 1) {
		throw GradeTooHighException();
	} else if (grade > 150) {
		throw GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src) {
	if (this != &src) {
		_grade = src._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {}


std::string	Bureaucrat::getName() const {
	return (_name);
}

int	Bureaucrat::getGrade() const {
	return (_grade);
}

void	Bureaucrat::incrementGrade() {
	if (_grade - 1 < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	_grade--;
}

void	Bureaucrat::decrementGrade() {
	if (_grade + 1 > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	_grade++;
}

void	Bureaucrat::signAForm(AForm& f) {
    try {
		f.beSigned(*this);
        std::cout << _name << " signed " << f.getName() << std::endl;
    } catch (std::exception& e) {
        std::cout << _name << " could not sign " << f.getName() 
                  << ", reason: " << e.what() << std::endl;
    }
}

void	Bureaucrat::executeForm(AForm const & f) {
	try {
		f.execute(*this);
		std::cout << _name << " executed " << f.getName() << std::endl;
	} catch (std::exception& e) {
		std::cout 	<< _name << " could not execute " << f.getName()
					<< ", reason: " << e.what() <<  std::endl;
	}
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& b) {
	o << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (o);
}