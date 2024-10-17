#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main() {
    Intern someRandomIntern;
    Bureaucrat boss("Boss", 1);

    try {
        // Successful form creation
        AForm* shrubbery = someRandomIntern.makeForm("shrubbery creation", "home");
        if (shrubbery) {
            boss.signAForm(*shrubbery);
            boss.executeForm(*shrubbery);
            delete shrubbery;  // Clean up dynamically allocated memory
        }

        // Test RobotomyRequestForm creation
        AForm* robotomy = someRandomIntern.makeForm("robotomy request", "Bender");
        if (robotomy) {
            boss.signAForm(*robotomy);
            boss.executeForm(*robotomy);
            delete robotomy;
        }

		AForm* presidental =  someRandomIntern.makeForm("presidential pardon", "Kate");
		if (presidental) {
			boss.signAForm(*presidental);
			boss.executeForm(*presidental);
			delete presidental;
		}

        // Invalid form creation
        AForm* invalidForm = someRandomIntern.makeForm("unknown form", "target");
        if (invalidForm) {
            delete invalidForm;
        }

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}