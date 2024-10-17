#include "AForm.hpp"

const char	*AForm::GradeTooHighException::what() const throw() {
	return ("Grade too high!");
}

const char *AForm::GradeTooLowException::what() const throw() {
	return ("Grade too low!");
}

const char *AForm::NotSignedException:: what() const throw() { 
	return ("Form not signed"); 
}

AForm::AForm(const std::string& name, const int signGrade, const int exGrade ):_name(name), _signGrade(signGrade), _exGrade(exGrade), _isSigned(0) {
	if (signGrade < 1 || exGrade < 1) {
		throw GradeTooHighException();
	} else if (signGrade > 150 || exGrade > 150) {
		throw GradeTooLowException();
	}
}

AForm::~AForm() {}

AForm::AForm( const AForm &copy): _name(copy._name), _signGrade(copy._signGrade), _exGrade(copy._exGrade) {}

AForm& AForm::operator=( const AForm &src) {
	if (this != &src) {
		_isSigned = src._isSigned;
	}
	return (*this);
}

int	AForm::getSignGrade() const {
	return _signGrade;
}

int	AForm::getExGrade() const {
	return _exGrade;
}

std::string	AForm::getName() const {
	return _name;
}

bool	AForm::getSignedStatus() const {
	return _isSigned;
}

void AForm::beSigned(Bureaucrat& Bureaucrat) {
	if (Bureaucrat.getGrade() <= _signGrade) {
		_isSigned = true;
	} else {
		throw GradeTooLowException();
	}
}

void	AForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() > _exGrade) {
		throw AForm::GradeTooLowException();
	}
	if (!_isSigned) {
		throw AForm::NotSignedException();
	}
	execution();
}

std::ostream& operator<<(std::ostream& o, AForm& f) {
	o	<< f.getName() 
		<< " AForm with sign grade: " << f.getSignGrade() 
		<< ", and execute grade: " << f.getExGrade() 
		<< ", is " << (f.getSignedStatus() ? "signed" : "not signed");
	return (o);
}