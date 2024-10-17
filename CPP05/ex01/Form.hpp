#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    public:
        Form( const std::string& name, const int signGrade, const int exGrade );
        ~Form();
        Form( const Form &copy);
        Form& operator=( const Form &src);

		//getters
        int	getSignGrade() const;
        int	getExGrade() const;
		std::string	getName() const;
		bool	getSignedStatus() const;

		void 	beSigned(Bureaucrat& Bureaucrat);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
    
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _signGrade;
        const int           _exGrade;

};

std::ostream& operator<<(std::ostream& o, Form& f);

#endif