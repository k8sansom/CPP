#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    // Test ShrubberyCreationForm
	std::cout << "Testing Shrubbery Creation Form" << std::endl;
    try {
        Bureaucrat alice("Alice", 137);
		Bureaucrat	mike("Mike", 145);
        ShrubberyCreationForm shrubbery("garden");

        // Trying to execute without signing the form
        alice.executeForm(shrubbery);  // Should throw "Form is not signed."

        // Sign the form
        shrubbery.beSigned(alice);     // Alice has sufficient grade to sign the form (145 required)
        alice.executeForm(shrubbery);  // Alice has enough grade to execute (137 required)
		mike.executeForm(shrubbery); // grade should be too low
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

	std::cout << std::endl;

    // Test RobotomyRequestForm
	std::cout << "Testing Robotomy Request Form" << std::endl;
    try {
		Bureaucrat bob("Bob", 42);  // Bob's grade is 50
		Bureaucrat kate("Kate", 120);
		RobotomyRequestForm robotomy("Wall-E");

		// Sign and execute the form
		// robotomy.beSigned(kate);
		robotomy.beSigned(bob);   // should work
		bob.executeForm(robotomy);  // should work but 50% robotomy fails
		bob.executeForm(robotomy);  // should work but 50% robotomy fails
		bob.executeForm(robotomy);  // should work but 50% robotomy fails
		kate.executeForm(robotomy); // Should fail because grade too low
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
	std::cout << std::endl;
    // Test PresidentialPardonForm
	std::cout << "Testing Presidential Pardon Form" << std::endl;
    try {
        Bureaucrat donald("Donald", 1);  // President's grade is 1
		Bureaucrat	kamala("Kamala", 7);
        PresidentialPardonForm pardon("Ford Prefect");

        // Sign and execute the form
        donald.executeForm(pardon);  // can't execute bc not signed
		pardon.beSigned(kamala);     // can sign
		kamala.executeForm(pardon);  //can't execute
		donald.executeForm(pardon);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}