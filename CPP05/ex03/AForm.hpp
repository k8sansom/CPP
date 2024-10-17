#ifndef AForm_HPP
#define AForm_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    public:
        AForm( const std::string& name, const int signGrade, const int exGrade );
        virtual ~AForm();
        AForm( const AForm &copy);
        AForm& operator=( const AForm &src);

		//getters
        int				getSignGrade() const;
        int				getExGrade() const;
		std::string		getName() const;
		bool			getSignedStatus() const;

		void 			beSigned(Bureaucrat& Bureaucrat); 
		void			execute(Bureaucrat const & executor) const;
        virtual void	execution() const = 0;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class NotSignedException : public std::exception {
        	public:
            	virtual const char* what() const throw();
    };
    
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _signGrade;
        const int           _exGrade;

};

std::ostream& operator<<(std::ostream& o, AForm& f);

#endif