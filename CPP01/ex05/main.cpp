#include "Harl.hpp"

int	main(void) {
	Harl		Harl;
	std::string	input;
	while (true) {
		std::cout << "Complaint level: ";
        std::getline(std::cin, input);
		if (std::cin.eof()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << std::endl;
			return 1;
		}
		if (input.compare("exit") == 0)
			break ;
		Harl.complain(input);
	}
	return 0;
}