#include "Form.hpp"

const char	*Form::GradeTooHighException::what() const throw() {
	return ("Grade too high!");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("Grade too low!");
}

Form::Form(const std::string& name, const int signGrade, const int exGrade ):_name(name), _signGrade(signGrade), _exGrade(exGrade), _isSigned(0) {
	if (signGrade < 1 || exGrade < 1) {
		throw GradeTooHighException();
	} else if (signGrade > 150 || exGrade > 150) {
		throw GradeTooLowException();
	}
}

Form::~Form() {}

Form::Form( const Form &copy): _name(copy._name), _signGrade(copy._signGrade), _exGrade(copy._exGrade) {}

Form& Form::operator=( const Form &src) {
	if (this != &src) {
		_isSigned = src._isSigned;
	}
	return (*this);
}

int	Form::getSignGrade() const {
	return _signGrade;
}

int	Form::getExGrade() const {
	return _exGrade;
}

std::string	Form::getName() const {
	return _name;
}

bool	Form::getSignedStatus() const {
	return _isSigned;
}

void Form::beSigned(Bureaucrat& Bureaucrat) {
	if (Bureaucrat.getGrade() <= _signGrade) {
		_isSigned = true;
	} else {
		throw GradeTooLowException();
	}
}

std::ostream& operator<<(std::ostream& o, Form& f) {
	o	<< f.getName() 
		<< " form with sign grade: " << f.getSignGrade() 
		<< ", and execute grade: " << f.getExGrade() 
		<< ", is " << (f.getSignedStatus() ? "signed" : "not signed");
	return (o);
}