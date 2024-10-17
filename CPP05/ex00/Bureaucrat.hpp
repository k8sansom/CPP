#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
    public:
		//OCF
		Bureaucrat(int grade, const std::string &name);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat& operator=(const Bureaucrat& src);

		//getters
		std::string	getName() const;
		int			getGrade() const;

		//grade changers
		void		incrementGrade();
		void		decrementGrade();

		//exception classes
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

    private:
		const std::string	_name;
		int					_grade;        
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& b);

#endif